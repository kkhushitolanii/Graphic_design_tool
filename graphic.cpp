#include <iostream>
#include <vector>

using namespace std;

// Function to display the canvas
void displayCanvas(const vector<string>& canvas) {
    for (const string& row : canvas) {
        cout << row << endl;
    }
}

int main() {
    const int canvasWidth = 30;
    const int canvasHeight = 20;

    vector<string> canvas(canvasHeight, string(canvasWidth, ' '));

    char choice;
    do {
        cout << "Choose a shape to draw:" << endl;
        cout << "1. Line" << endl;
        cout << "2. Circle" << endl;
        cout << "3. Rectangle" << endl;
        cout << "4. Quit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case '1': // Draw Line
                int x1, y1, x2, y2;
                cout << "Enter starting coordinates (x1 y1): ";
                cin >> x1 >> y1;
                cout << "Enter ending coordinates (x2 y2): ";
                cin >> x2 >> y2;

                if (x1 >= 0 && x1 < canvasWidth && y1 >= 0 && y1 < canvasHeight &&
                    x2 >= 0 && x2 < canvasWidth && y2 >= 0 && y2 < canvasHeight) {
                    if (x1 == x2) { // Vertical Line
                        for (int y = min(y1, y2); y <= max(y1, y2); ++y) {
                            canvas[y][x1] = '*';
                        }
                    } else if (y1 == y2) { // Horizontal Line
                        for (int x = min(x1, x2); x <= max(x1, x2); ++x) {
                            canvas[y1][x] = '*';
                        }
                    }
                }
                break;

            case '2': // Draw Circle (not implemented in this basic example)
                cout << "Circle drawing is not implemented in this example." << endl;
                break;

            case '3': // Draw Rectangle (not implemented in this basic example)
                cout << "Rectangle drawing is not implemented in this example." << endl;
                break;

            case '4':
                cout << "Exiting the drawing tool." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
        }

        displayCanvas(canvas);

    } while (choice != '4');

    return 0;
}