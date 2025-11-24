#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TT;
    cin >> TT;

    // Global “intern” table: each unique set<int> maps to an ID
    map< set<int>, int > canon;
    vector< set<int> > sets;

    // Pre-intern the empty set with ID = 0
    {
        set<int> empty;
        canon[empty] = 0;
        sets.push_back(empty);
    }

    while (TT--) {
        int Q;
        cin >> Q;
        stack<int> st;

        while (Q--) {
            string op;
            cin >> op;

            if (op == "PUSH") {
                // push the empty set
                st.push(0);
            }
            else if (op == "DUP") {
                st.push(st.top());
            }
            else {
                // All other ops consume two IDs
                int id1 = st.top(); st.pop();
                int id2 = st.top(); st.pop();

                const set<int>& A = sets[id1];
                const set<int>& B = sets[id2];

                set<int> R;
                if (op == "UNION") {
                    // merge smaller into larger
                    if (A.size() < B.size()) {
                        R = B;
                        R.insert(A.begin(), A.end());
                    } else {
                        R = A;
                        R.insert(B.begin(), B.end());
                    }
                }
                else if (op == "INTERSECT") {
                    // iterate the smaller for intersection
                    if (A.size() < B.size()) {
                        for (set<int>::const_iterator it = A.begin(); it != A.end(); ++it) {
                            if (B.count(*it)) R.insert(*it);
                        }
                    } else {
                        for (set<int>::const_iterator it = B.begin(); it != B.end(); ++it) {
                            if (A.count(*it)) R.insert(*it);
                        }
                    }
                }
                else if (op == "ADD") {
                    // ADD: insert the entire set-id1 as an element into set-id2
                    R = B;
                    R.insert(id1);
                }

                // Intern R → get its unique ID
                map< set<int>, int >::iterator it = canon.find(R);
                int newID;
                if (it != canon.end()) {
                    newID = it->second;
                } else {
                    newID = sets.size();
                    sets.push_back(R);
                    canon[R] = newID;
                }
                st.push(newID);
            }

            // Output size of the set on top of the stack
            cout << sets[ st.top() ].size() << "\n";
        }

        // Test-case separator
        cout << "***\n";
    }

    return 0;
}
