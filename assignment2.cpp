// Reg ID: BC220406834
// Name: Umair Aftab
#include <iostream>
#include <stack>
#include <string>

class Book
{
public:
    std::string title;
    std::string author;
    std::string ISBN;

    Book(std::string t, std::string a, std::string i) : title(t), author(a), ISBN(i) {}
};

class TreeNode
{
public:
    Book data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(Book b) : data(b), left(nullptr), right(nullptr) {}
};

class BookStack
{
private:
    std::stack<Book> bookStack;
    TreeNode *root;

public:
    BookStack() : root(nullptr) {}

    void push(Book newBook)
    {
        bookStack.push(newBook);
        root = insert(root, newBook);
    }

    void pop()
    {
        if (!bookStack.empty())
        {
            bookStack.pop();
            root = removeMostRecent(root);
        }
        else
        {
            std::cout << "The library is empty." << std::endl;
        }
    }

    Book *search(std::string title)
    {
        return searchBook(root, title);
    }

    void listBooks()
    {
        inOrderTraversal(root);
    }

    void update(std::string oldTitle, Book updatedBook)
    {
        remove(oldTitle);
        push(updatedBook);
    }

private:
    TreeNode *insert(TreeNode *node, Book newBook)
    {
        if (node == nullptr)
        {
            return new TreeNode(newBook);
        }

        if (newBook.title < node->data.title)
        {
            node->left = insert(node->left, newBook);
        }
        else if (newBook.title > node->data.title)
        {
            node->right = insert(node->right, newBook);
        }

        return node;
    }

    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *removeMostRecent(TreeNode *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        if (node->right == nullptr)
        {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        TreeNode *min = findMin(node->right);
        node->data = min->data;
        node->right = removeMostRecent(node->right);

        return node;
    }

    Book *searchBook(TreeNode *node, std::string title)
    {
        while (node != nullptr)
        {
            if (title == node->data.title)
            {
                return &node->data;
            }
            else if (title < node->data.title)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return nullptr;
    }

    void inOrderTraversal(TreeNode *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            std::cout << "Title: " << node->data.title << ", Author: " << node->data.author << ", ISBN: " << node->data.ISBN << std::endl;
            inOrderTraversal(node->right);
        }
    }

    void remove(std::string title)
    {
        root = removeBook(root, title);
    }

    TreeNode *removeBook(TreeNode *node, std::string title)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (title < node->data.title)
        {
            node->left = removeBook(node->left, title);
        }
        else if (title > node->data.title)
        {
            node->right = removeBook(node->right, title);
        }
        else
        {
            // Node with only one child or no child
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children, get the inorder successor
            TreeNode *min = findMin(node->right);
            node->data = min->data;
            node->right = removeBook(node->right, min->data.title);
        }

        return node;
    }
};

int main()
{
    BookStack library;

    char choice;
    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a Book\n";
        std::cout << "2. Remove the Most Recently Added Book\n";
        std::cout << "3. Search for a Book\n";
        std::cout << "4. List All Books\n";
        std::cout << "5. Update a Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character in the buffer

        switch (choice)
        {
        case '1':
        {
            std::string title, author, ISBN;
            std::cout << "Enter Book Title: ";
            std::getline(std::cin, title);
            std::cout << "Enter Author: ";
            std::getline(std::cin, author);
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, ISBN);

            library.push(Book(title, author, ISBN));
            break;
        }
        case '2':
            library.pop();
            std::cout << "Most Recently Added Book Removed.\n";
            break;
        case '3':
        {
            std::string title;
            std::cout << "Enter Book Title to Search: ";
            std::getline(std::cin, title);

            Book *result = library.search(title);
            if (result != nullptr)
            {
                std::cout << "Book Found:\n";
                std::cout << "Title: " << result->title << ", Author: " << result->author << ", ISBN: " << result->ISBN << std::endl;
            }
            else
            {
                std::cout << "Book not found.\n";
            }
            break;
        }
        case '4':
            std::cout << "List of Books in the Library:\n";
            library.listBooks();
            break;
        case '5':
        {
            std::string oldTitle, newTitle, author, ISBN;
            std::cout << "Enter the Title of the Book to Update: ";
            std::getline(std::cin, oldTitle);
            std::cout << "Enter New Book Title: ";
            std::getline(std::cin, newTitle);
            std::cout << "Enter Author: ";
            std::getline(std::cin, author);
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, ISBN);

            library.update(oldTitle, Book(newTitle, author, ISBN));
            std::cout << "Book Updated.\n";
            break;
        }
        case '6':
            std::cout << "Exiting Program.\n";
            break;
        default:
            std::cout << "Invalid Choice. Please enter a valid option.\n";
        }
    } while (choice != '6');

    return 0;
}