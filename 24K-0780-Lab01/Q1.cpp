#include <iostream>
#include <string>

using namespace std;

class ResearchPaper {
private:
    string* authors;
    int count;

public:
    ResearchPaper(string arr[], int n) {
        count = n;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = arr[i];
        }
    }

    ~ResearchPaper() {
        delete[] authors;
    }

    ResearchPaper(const ResearchPaper& other) {
        count = other.count;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = other.authors[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& other) {
        if (this == &other)
            return *this;
        delete[] authors;
        count = other.count;
        authors = new string[count];
        for (int i = 0; i < count; i++) {
            authors[i] = other.authors[i];
        }
        return *this;
    }

    void display() const {
        cout << "Authors: ";
        for (int i = 0; i < count; i++) {
            cout << authors[i];
            if (i < count - 1) cout << ", ";
        }
        cout << endl;
    }

    void setAuthor(int index, const string& name) {
        if (index >= 0 && index < count) {
            authors[index] = name;
        }
    }
};

int main() {
    string authors1[] = {"Albert Einstein", "Isaac Newton", "Marie Curie"};
    ResearchPaper paper1(authors1, 3);

    cout << "Paper 1:" << endl;
    paper1.display();

    ResearchPaper paper2 = paper1;
    cout << "Paper 2 (copy of Paper 1):" << endl;
    paper2.display();

    paper2.setAuthor(1, "Niels Bohr");
    cout << "\nAfter modifying Paper 2:" << endl;
    paper1.display();
    paper2.display();

    string authors2[] = {"Galileo Galilei", "Stephen Hawking"};
    ResearchPaper paper3(authors2, 2);
    cout << "\nPaper 3:" << endl;
    paper3.display();

    paper3 = paper1;
    cout << "Paper 3 after assignment from Paper 1:" << endl;
    paper3.display();

    paper3.setAuthor(0, "Richard Feynman");
    cout << "\nAfter modifying Paper 3:" << endl;
    paper1.display();
    paper3.display();

    return 0;
}

