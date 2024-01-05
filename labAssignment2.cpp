// REG ID: BC220406834
// Name: Umair Aftab
#include <iostream>
#include <string>

class TreeNode
{
public:
    std::string studentName;
    TreeNode *left;
    TreeNode *right;

    TreeNode(std::string name) : studentName(name), left(nullptr), right(nullptr) {}
};

class StudentSeating
{
private:
    TreeNode *root;

public:
    StudentSeating() : root(nullptr) {}

    void addStudent(std::string name)
    {
        root = insert(root, name);
    }

    void removeStudent(std::string name)
    {
        root = remove(root, name);
    }

    void displaySeatingArrangement()
    {
        std::cout << "Current Seating Arrangement (Alphabetical Order):\n";
        inOrderTraversal(root);
        std::cout << std::endl;
    }

private:
    TreeNode *insert(TreeNode *node, std::string name)
    {
        if (node == nullptr)
        {
            return new TreeNode(name);
        }

        if (name < node->studentName)
        {
            node->left = insert(node->left, name);
        }
        else if (name > node->studentName)
        {
            node->right = insert(node->right, name);
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

    TreeNode *remove(TreeNode *node, std::string name)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (name < node->studentName)
        {
            node->left = remove(node->left, name);
        }
        else if (name > node->studentName)
        {
            node->right = remove(node->right, name);
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
            node->studentName = min->studentName;
            node->right = remove(node->right, min->studentName);
        }

        return node;
    }

    void inOrderTraversal(TreeNode *node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            std::cout << node->studentName << " ";
            inOrderTraversal(node->right);
        }
    }
};

int main()
{
    StudentSeating seating;

    char choice;
    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a Student\n";
        std::cout << "2. Remove a Student\n";
        std::cout << "3. Display Seating Arrangement\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character in the buffer

        switch (choice)
        {
        case '1':
        {
            std::string name;
            std::cout << "Enter Student Name: ";
            std::getline(std::cin, name);

            seating.addStudent(name);
            break;
        }
        case '2':
        {
            std::string name;
            std::cout << "Enter Student Name to Remove: ";
            std::getline(std::cin, name);

            seating.removeStudent(name);
            break;
        }
        case '3':
            seating.displaySeatingArrangement();
            break;
        case '4':
            std::cout << "Exiting Program.\n";
            break;
        default:
            std::cout << "Invalid Choice. Please enter a valid option.\n";
        }
    } while (choice != '4');

    return 0;
}