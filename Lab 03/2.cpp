#include <iostream>
using namespace std;

class FitnessTracker
{
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string name, int goal)
    {
        userName = name;
        dailyStepGoal = goal;
        stepsTaken = 0;
    }
    void addSteps(int steps)
    {
        if (steps > 0)
        {
            stepsTaken += steps;
            cout << steps << " Steps More Taken! " << endl;
            cout << "Total Steps Taken Today: " << stepsTaken << endl;
            calculateCalories();
        }
        else
        {
            cout << "No Steps Taken Today! " << endl;
        }
    }
    void calculateCalories()
    {
        caloriesBurned = stepsTaken * 0.04;
        cout << "Calories Burnt: " << caloriesBurned << endl
             << endl;
    }
    void checkGoal()
    {
        cout << endl
             << "------------Daily Goal Status------------" << endl;
        if (stepsTaken >= dailyStepGoal)
        {
            cout << "Well Done, You achieved your daily steps goal by" << (stepsTaken - dailyStepGoal) << " steps!" << endl;
        }
        else
        {
            cout << "Keep Going, " << (dailyStepGoal - stepsTaken) << " more steps to be taken to achieve your daily steps goal!" << endl
                 << endl;
        }
    }
};
int main()
{
    FitnessTracker tracker("Laiba", 8000);
    cout << endl
         << "------------Progress Throughout The Day------------" << endl;
    tracker.addSteps(1200);
    tracker.addSteps(900);
    tracker.addSteps(1500);
    tracker.addSteps(1100);
    tracker.addSteps(800);

    tracker.checkGoal();
    return 0;
}
