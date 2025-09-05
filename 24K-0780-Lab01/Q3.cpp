#include <iostream>

using namespace std;

class Exam {
private:
    int* marks;

public:
    Exam(int m) {
        marks = new int(m);
    }

    ~Exam() {
        delete marks;
    }

    void setMarks(int m) {
        *marks = m;
    }

    int getMarks() const {
        return *marks;
    }
};

int main() {
    Exam e1(85);
    cout << "Exam 1 marks: " << e1.getMarks() << endl;

    Exam e2 = e1;  // shallow copy (default copy constructor)
    cout << "Exam 2 marks (copied from Exam 1): " << e2.getMarks() << endl;

    e2.setMarks(95);
    cout << "\nAfter changing Exam 2 marks:" << endl;
    cout << "Exam 1 marks: " << e1.getMarks() << endl;
    cout << "Exam 2 marks: " << e2.getMarks() << endl;

    return 0;
}

