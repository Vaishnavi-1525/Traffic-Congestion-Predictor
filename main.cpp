
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

int convertTo24HourFormat(const string& time) {
    int hour, minute;
    char meridian[3];
    sscanf(time.c_str(), "%d:%d %s", &hour, &minute, meridian);

    if (tolower(meridian[0]) == 'p' && hour != 12) {
        hour += 12;
    } else if (tolower(meridian[0]) == 'a' && hour == 12) {
        hour = 0;
    }

    return hour * 100 + minute;
}

string predictCongestion(const string& time, const string& location, const string& weather) {
    int time24 = convertTo24HourFormat(time);

    if (weather == "Rainy" || location == "Downtown" || location == "Market Area" ||
        (time24 >= 700 && time24 <= 900) || (time24 >= 1700 && time24 <= 1900)) {
        return "High Congestion";
    } else if ((time24 >= 900 && time24 < 1700)) {
        return "Medium Congestion";
    }
    return "Low Congestion";
}

void displayVisualization(const string& congestion) {
    cout << "Traffic Level: " << congestion << "\n";
    cout << "[";
    int barLength = (congestion == "High Congestion") ? 10 : (congestion == "Medium Congestion") ? 6 : 3;
    for (int i = 0; i < barLength; i++) cout << "#";
    for (int i = barLength; i < 10; i++) cout << " ";
    cout << "]\n";
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    const string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string date = to_string(ltm->tm_mday) + "-" + months[ltm->tm_mon] + "-" + to_string(1900 + ltm->tm_year);
    return date;
}

void generateReport(const string& time, const string& location, const string& weather, const string& congestion) {
    ofstream report("TrafficReport.txt", ios::app);
    if (report.is_open()) {
        report << "Traffic Prediction Report\n";
        report << "-------------------------\n";
        report << "Date: " << getCurrentDate() << "\n";
        report << "Time: " << time << "\n";
        report << "Location: " << location << "\n";
        report << "Weather: " << weather << "\n";
        report << "Predicted Congestion: " << congestion << "\n\n";
        report.close();
        cout << "Report saved to 'TrafficReport.txt'.\n";
    } else {
        cerr << "Error: Could not save the report.\n";
    }
}

string getLocation() {
    cout << "\nSelect a location:\n";
    cout << "1. Downtown\n";
    cout << "2. Market Area\n";
    cout << "3. Residential Area\n";
    cout << "4. Highway\n";
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: return "Downtown";
        case 2: return "Market Area";
        case 3: return "Residential Area";
        case 4: return "Highway";
        default: cout << "Invalid choice. Defaulting to Residential Area.\n"; return "Residential Area";
    }
}

string getWeather() {
    cout << "\nSelect the weather condition:\n";
    cout << "1. Sunny\n";
    cout << "2. Rainy\n";
    cout << "3. Cloudy\n";
    cout << "4. Foggy\n";
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: return "Sunny";
        case 2: return "Rainy";
        case 3: return "Cloudy";
        case 4: return "Foggy";
        default: cout << "Invalid choice. Defaulting to Sunny.\n"; return "Sunny";
    }
}

int main() {
    cout << "Welcome to the Traffic Congestion Predictor!\n";

    string time, location, weather;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') {
        cout << "Enter time (HH:MM AM/PM): ";
        cin.ignore();
        getline(cin, time);

        location = getLocation();
        weather = getWeather();

        string congestion = predictCongestion(time, location, weather);
        displayVisualization(congestion);
        generateReport(time, location, weather, congestion);

        cout << "\nDo you want to make another prediction? (y/n): ";
        cin >> cont;
    }

    cout << "Thank you for using the Traffic Congestion Predictor!\n";
    return 0;
}
