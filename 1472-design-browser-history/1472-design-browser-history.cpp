class Node {
public:
    string data;
    Node* next;
    Node* back;

    // Constructor to initialize a new node
    Node(string url) {
        data = url;
        next = nullptr;
        back = nullptr;
    }
};

class BrowserHistory {
    Node* currentPage;

public:
    // Initialize browser with homepage
    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }

    // Visit a new page
    void visit(string url) {

        // Delete all forward history
        // if (currentPage->next) {
        //     Node* temp = currentPage->next;

        //     while (temp) {
        //         Node* nextNode = temp->next;
        //         delete temp;
        //         temp = nextNode;
        //     }

        //     currentPage->next = nullptr;
        // }

        // Create and connect the new page
        Node* newNode = new Node(url);

        currentPage->next = newNode;
        newNode->back = currentPage;

        currentPage = newNode;
    }

    // Move back by at most 'steps' pages
    string back(int steps) {

        while (steps > 0 && currentPage->back) {
            currentPage = currentPage->back;
            steps--;
        }

        return currentPage->data;
    }

    // Move forward by at most 'steps' pages
    string forward(int steps) {

        while (steps > 0 && currentPage->next) {
            currentPage = currentPage->next;
            steps--;
        }

        return currentPage->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */