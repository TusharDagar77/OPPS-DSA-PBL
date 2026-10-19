#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAX_LOCATIONS = 10;
struct Service {
    int id;
    char name[100];
    char category[50];
    char area[100];
    int locationNode;
    Service* next;
};
struct Road {
    int distance;
    int traffic;
    int condition;
    bool closed;
};
class SmartCity {
private:
    Service* head;
    string locations[MAX_LOCATIONS];
    Road roads[MAX_LOCATIONS][MAX_LOCATIONS];
    int locationCount;
    int weight(const Road& r) {
        return r.distance + (r.traffic - 1) * 3 + (r.condition - 1) * 2;
    }
    bool validLocation(int n) {
        return n >= 0 && n < locationCount;
    }
    void clearInput() {
        cin.clear();
        cin.ignore(10000, '\n');
    }
public:
    SmartCity() {
        head = NULL;
        locationCount = 8;
        locations[0] = "AIIMS / Ansari Nagar";
        locations[1] = "Safdarjung Hospital";
        locations[2] = "IIT Delhi / Hauz Khas";
        locations[3] = "Delhi University / North Campus";
        locations[4] = "New Delhi Railway Station";
        locations[5] = "Kashmere Gate ISBT";
        locations[6] = "Connaught Place";
        locations[7] = "Saket / Select CITYWALK";
        for (int i = 0; i < MAX_LOCATIONS; i++) {
            for (int j = 0; j < MAX_LOCATIONS; j++) {
                roads[i][j].distance = 0;
                roads[i][j].traffic = 1;
                roads[i][j].condition = 1;
                roads[i][j].closed = false;
            }
        }
        addRoad(0, 1, 4);
        addRoad(0, 2, 8);
        addRoad(1, 7, 7);
        addRoad(2, 3, 12);
        addRoad(2, 7, 6);
        addRoad(3, 6, 9);
        addRoad(4, 6, 3);
        addRoad(4, 5, 6);
        addRoad(5, 6, 5);
        addRoad(6, 7, 11);
        addService(1, "AIIMS New Delhi", "Hospital", "Ansari Nagar, New Delhi", 0);
        addService(2, "Safdarjung Hospital", "Hospital", "New Delhi", 1);
        addService(3, "Max Super Speciality Hospital", "Hospital", "Saket, New Delhi", 7);
        addService(4, "Fortis Hospital Shalimar Bagh", "Hospital", "Shalimar Bagh, New Delhi", 3);
        addService(5, "University of Delhi", "Education", "North Campus, Delhi", 3);
        addService(6, "IIT Delhi", "Education", "Hauz Khas, New Delhi", 2);
        addService(7, "Graphic Era Deemed to be University", "Education", "Dehradun", 2);
        addService(8, "Connaught Place Police Station", "Emergency", "Connaught Place, Delhi", 6);
        addService(9, "New Delhi Railway Station", "Transport", "New Delhi", 4);
        addService(10, "Kashmere Gate ISBT", "Transport", "Delhi", 5);
        addService(11, "Select CITYWALK", "Shopping Mall", "Saket, New Delhi", 7);
        addService(12, "Pacific Mall", "Shopping Mall", "Tagore Garden, New Delhi", 5);
        addService(13, "SBI Connaught Place", "Bank", "Connaught Place, New Delhi", 6);
        addService(14, "HDFC Bank Saket", "Bank", "Saket, New Delhi", 7);
        addService(15, "Haldiram's Connaught Place", "Restaurant", "Connaught Place, New Delhi", 6);
        addService(16, "Domino's Pizza Saket", "Restaurant", "Saket, New Delhi", 7);
        addService(17, "India Post Office Connaught Place", "Government Service", "Connaught Place, Delhi", 6);
        addService(18, "India Gate", "Tourist Attraction", "New Delhi", 6);
        addService(19, "Indian Oil Petrol Pump", "Fuel Station", "New Delhi", 4);
        addService(20, "Lodhi Garden", "Park", "New Delhi", 1);
    }
    ~SmartCity() {
        Service* p = head;
        while (p != NULL) {
            Service* temp = p;
            p = p->next;
            free(temp);
        }
    }
    void addService(int id, string name, string category, string area, int node) {
        Service* newNode = (Service*)malloc(sizeof(Service));
        if (newNode == NULL) {
            cout << "Memory allocation failed. Service was not added.\n";
            return;
        }
        newNode->id = id;
        strncpy(newNode->name, name.c_str(), sizeof(newNode->name) - 1);
        newNode->name[sizeof(newNode->name) - 1] = '\0';
        strncpy(newNode->category, category.c_str(), sizeof(newNode->category) - 1);
        newNode->category[sizeof(newNode->category) - 1] = '\0';
        strncpy(newNode->area, area.c_str(), sizeof(newNode->area) - 1);
        newNode->area[sizeof(newNode->area) - 1] = '\0';
        newNode->locationNode = node;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            Service* p = head;
            while (p->next != NULL) p = p->next;
            p->next = newNode;
        }
    }
    void addServiceFromUser() {
        int id = 1;
        Service* p = head;
        while (p != NULL) {
            if (p->id >= id) id = p->id + 1;
            p = p->next;
        }
        string name, category, area;
        int node;
        cout << "Enter service name: ";
        getline(cin >> ws, name);
        cout << "Enter category (Hospital, Education, Bank, etc.): ";
        getline(cin, category);
        cout << "Enter area/location: ";
        getline(cin, area);
        showLocations();
        cout << "Enter matching location node number: ";
        if (!(cin >> node)) {
            clearInput();
            cout << "Invalid input. Service was not added.\n";
            return;
        }
        if (!validLocation(node)) {
            cout << "Invalid location node. Service was not added.\n";
            return;
        }
        addService(id, name, category, area, node);
        cout << "Service added successfully with ID " << id << ".\n";
    }
    void displayServices() {
        Service* p = head;
        if (p == NULL) {
            cout << "No services available.\n";
            return;
        }
        cout << "\n--- CITY SERVICES ---\n";
        while (p != NULL) {
            cout << "ID: " << p->id
                 << " | Name: " << p->name
                 << " | Category: " << p->category
                 << " | Area: " << p->area
                 << " | Location node: " << p->locationNode << "\n";
            p = p->next;
        }
    }
    void searchService() {
        string key;
        cout << "Enter service name or category to search: ";
        getline(cin >> ws, key);
        Service* p = head;
        bool found = false;
        while (p != NULL) {
            if (string(p->name).find(key) != string::npos ||
                string(p->category).find(key) != string::npos) {
                cout << "ID: " << p->id << " | " << p->name
                     << " | " << p->category << " | " << p->area << "\n";
                found = true;
            }
            p = p->next;
        }
        if (!found) cout << "No matching service found.\n";
    }
    void showLocations() {
        cout << "\n--- LOCATION NODES ---\n";
        for (int i = 0; i < locationCount; i++)
            cout << i << ". " << locations[i] << "\n";
    }
    void addRoad(int a, int b, int km) {
        if (a < 0 || b < 0 || a >= MAX_LOCATIONS ||
            b >= MAX_LOCATIONS || a == b || km <= 0) return;
        roads[a][b].distance = km;
        roads[b][a].distance = km;
    }
    void showRoads() {
        cout << "\n--- ROAD CONNECTIONS ---\n";
        for (int i = 0; i < locationCount; i++) {
            for (int j = i + 1; j < locationCount; j++) {
                if (roads[i][j].distance > 0) {
                    cout << i << " (" << locations[i] << ") <-> "
                         << j << " (" << locations[j] << "), "
                         << roads[i][j].distance << " km, Traffic: "
                         << roads[i][j].traffic << ", Condition: "
                         << roads[i][j].condition << ", "
                         << (roads[i][j].closed ? "Closed" : "Open") << "\n";
                }
            }
        }
    }
    void updateRoad() {
        int a, b, traffic, condition, closed;
        showLocations();
        cout << "Enter first node: ";
        if (!(cin >> a)) { clearInput(); cout << "Invalid input.\n"; return; }
        cout << "Enter second node: ";
        if (!(cin >> b)) { clearInput(); cout << "Invalid input.\n"; return; }
        if (!validLocation(a) || !validLocation(b) || a == b ||
            roads[a][b].distance == 0) {
            cout << "Invalid nodes or no direct road between them.\n";
            return;
        }
        cout << "Traffic (1 Low, 2 Medium, 3 High): ";
        if (!(cin >> traffic)) { clearInput(); cout << "Invalid input.\n"; return; }
        cout << "Road condition (1 Good, 2 Fair, 3 Poor): ";
        if (!(cin >> condition)) { clearInput(); cout << "Invalid input.\n"; return; }
        cout << "Closed? (1 Yes, 0 No): ";
        if (!(cin >> closed)) { clearInput(); cout << "Invalid input.\n"; return; }
        if (traffic < 1 || traffic > 3 || condition < 1 || condition > 3 ||
            (closed != 0 && closed != 1)) {
            cout << "Invalid values. No changes made.\n";
            return;
        }
        roads[a][b].traffic = roads[b][a].traffic = traffic;
        roads[a][b].condition = roads[b][a].condition = condition;
        roads[a][b].closed = roads[b][a].closed = (closed == 1);
        cout << "Road information updated.\n";
    }
    void shortestRoute() {
        int start, destination;
        showLocations();
        cout << "Enter starting node: ";
        if (!(cin >> start)) { clearInput(); cout << "Invalid input.\n"; return; }
        cout << "Enter destination node: ";
        if (!(cin >> destination)) { clearInput(); cout << "Invalid input.\n"; return; }
        if (!validLocation(start) || !validLocation(destination)) {
            cout << "Invalid location number.\n";
            return;
        }
        const int INF = 1000000000;
        int dist[MAX_LOCATIONS], previous[MAX_LOCATIONS];
        bool visited[MAX_LOCATIONS];
        for (int i = 0; i < locationCount; i++) {
            dist[i] = INF;
            previous[i] = -1;
            visited[i] = false;
        }
        dist[start] = 0;
        for (int count = 0; count < locationCount; count++) {
            int u = -1;
            int best = INF;
            for (int i = 0; i < locationCount; i++) {
                if (!visited[i] && dist[i] < best) {
                    best = dist[i];
                    u = i;
                }
            }
            if (u == -1) break;
            visited[u] = true;
            for (int v = 0; v < locationCount; v++) {
                if (roads[u][v].distance > 0 && !roads[u][v].closed &&
                    !visited[v]) {
                    int cost = weight(roads[u][v]);
                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                        previous[v] = u;
                    }
                }
            }
        }
        if (dist[destination] == INF) {
            cout << "No open route found between these locations.\n";
            return;
        }
        int path[MAX_LOCATIONS], pathSize = 0;
        int current = destination;
        while (current != -1 && pathSize < MAX_LOCATIONS) {
            path[pathSize] = current;
            pathSize++;
            current = previous[current];
        }
        cout << "Recommended route (based on sample distance/traffic/road scores):\n";
        for (int i = pathSize - 1; i >= 0; i--) {
            cout << locations[path[i]];
            if (i > 0) cout << " -> ";
        }
        cout << "\nRoute score: " << dist[destination] << "\n";
        cout << "Note: route score is a demo score, not actual kilometres or live travel time.\n";
    }
    void menu() {
        int choice;
        do {
            cout << "\n========================================\n";
            cout << " SMART CITY SERVICES & ROUTE MANAGEMENT\n";
            cout << "========================================\n";
            cout << "1. Display all services\n";
            cout << "2. Search service\n";
            cout << "3. Add a new service\n";
            cout << "4. Display location nodes\n";
            cout << "5. Display road connections\n";
            cout << "6. Find best available route\n";
            cout << "7. Update traffic/road condition/closure\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            if (!(cin >> choice)) {
                clearInput();
                cout << "Please enter a number from the menu.\n";
                continue;
            }
            switch (choice) {
                case 1: displayServices(); break;
                case 2: searchService(); break;
                case 3: addServiceFromUser(); break;
                case 4: showLocations(); break;
                case 5: showRoads(); break;
                case 6: shortestRoute(); break;
                case 7: updateRoad(); break;
                case 0: cout << "Thank you for using the system.\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};
int main() {
    SmartCity city;
    city.menu();
    return 0;
}
