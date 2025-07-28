
# Traffic-Congestion-Predictor

A C++ console-based traffic congestion predictor that uses real-time inputs such as time, location, and weather to predict traffic congestion levels.

## 🚦 Features

- Predicts congestion level (Low, Medium, High)
- Accepts user inputs for:
  - Time (in 12-hour format)
  - Location (Downtown, Market Area, etc.)
  - Weather (Sunny, Rainy, etc.)
- Displays a visual representation of congestion
- Saves each prediction to a report file `TrafficReport.txt`

## 📁 How to Run

1. Compile the C++ file:
   ```
   g++ main.cpp -o TrafficPredictor
   ```

2. Run the executable:
   ```
   ./TrafficPredictor
   ```

## 📊 Example Output

```
Welcome to the Traffic Congestion Predictor!
Enter time (HH:MM AM/PM): 08:30 AM
Select a location:
1. Downtown
2. Market Area
3. Residential Area
4. Highway
>> 1
Select the weather condition:
1. Sunny
2. Rainy
3. Cloudy
4. Foggy
>> 2

Traffic Level: High Congestion
[##########]
Report saved to 'TrafficReport.txt'.
```

## 📄 Report Format

```
Traffic Prediction Report
-------------------------
Date: 28-Jul-2025
Time: 08:30 AM
Location: Downtown
Weather: Rainy
Predicted Congestion: High Congestion
```

## 🛠 Requirements

- C++ compiler (e.g., g++)
- Console/terminal

## 📂 Files Included

- `main.cpp` – Source code
- `README.md` – Project description and instructions
- `TrafficReport.txt` – (generated at runtime) Prediction reports


*Created as part of an academic project.*
