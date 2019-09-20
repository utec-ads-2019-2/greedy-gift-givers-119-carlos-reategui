#include <iostream>
#include <map>
using namespace std;

int main() {
    unsigned int numberOfPeople, count = 0;
    while (cin >> numberOfPeople) {
        map<string, int> netWorth;
        string names[numberOfPeople];
        for (unsigned int i = 0; i < numberOfPeople; ++i) {
            cin >> names[i];
            netWorth[names[i]] = 0;
        }
        for (unsigned int i = 0; i < numberOfPeople; ++i) {
            string person;
            unsigned int money, peopleToBeGifted;
            cin >> person >> money >> peopleToBeGifted;
            if (peopleToBeGifted == 0) continue;
            unsigned int moneyToBeSpentOnEachPerson = money / peopleToBeGifted;
            netWorth[person] -= moneyToBeSpentOnEachPerson * peopleToBeGifted;
            for (unsigned int j = 0; j < peopleToBeGifted; ++j) {
                cin >> person;
                netWorth[person] += moneyToBeSpentOnEachPerson;
            }
        }
        if (count++ > 0) cout << endl;
        for (unsigned int i = 0; i < numberOfPeople; ++i)
            cout << names[i] << " " << netWorth[names[i]] << endl;
    }
    return 0;
}