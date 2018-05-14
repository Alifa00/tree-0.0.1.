#include <iostream>
class tree_t
{
private:
    struct node_t {
        node_t * left;
        node_t * right;
        int value;
        node_t(int val) {
            left = nullptr;
            right = nullptr;
            value = val;
        }
        ~node_t() {
            delete left;
            delete right;
        }
        void add(int val) {
            if (value > val) {
                if (!left) {
                    left = new node_t(val);
                }
                else left->add(val);
            }
            else if (value < val) {
                if (!right) {
                    right = new node_t(val);
                }
                else right->add(val);
            }
            return;
        }
        bool find_t(int val) const {
            if (value == val) {
                return true;
            }
            if (value > val) {
                if (left) {
                    return left->find_t(val);
                }
                else return false;
            }
            if (value < val) {
                if (right) {
                    return right->find_t(val);
                }
                else return false;
            }
            else return false;
        }
        void print_t(std::ostream & stream, int num = 0) const{
            if (right) {
                right->print_t(stream, num + 4);
            }
            for (int i = 0; i < num + 4; i++) {
                stream << '-';
            }
            stream << value << '\n';
            if (left) {
                left->print_t(stream, num + 4);
            }
            return;
        }
    };
private:
    node_t * root_;
public:
    tree_t() {
        root_ = nullptr;
    }
    ~tree_t() {
        delete root_;
    }
    void insert(int value) {
        if (!root_) {
            root_ = new node_t;
            root_->value = value;
            return;
        }
        else {
            root_->add(value);
            return;
        }
    }
    bool find(int value) const {
        if (root_) {
            return root_->find_t(value);
        }
        return false;
    }
    void print(std::ostream & stream) const {
        if (root_) {
            root_->print_t(stream, 0);
        }
        else std::cout << "Tree is empty\n";
        return;
    }
};
int main() {
    tree_t tree;
    char op;
    while (std::cin >> op && op != 'q') {
        int num;
        switch (op) {
            case '=':
                tree.print(std::cout);
                break;
            case '+':
                if (std::cin >> num) {
                    tree.insert(num);
                    tree.print(std::cout);
                }
                else {
                    std::cout << "An error has occured while reading input data\n";
                    exit(0);
                }
                break;
            case '?':
                if (std::cin >> num) {
                    if (tree.find(num)) {
                        std::cout << "true\n";
                    }
                else {
                        std::cout << "false\n";
                    }
                }
                else {
                    std::cout << "An error has occured while reading input data\n";
                    exit(0);
                }
                break;
        }
    }
    return 0;
}
