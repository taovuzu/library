struct State {
    long long count; // How many valid numbers exist
    long long value; // The actual answer (sum, occurrences, etc.)
};

State dp[20][2][2][/*CustomConstraints*/]; // idx, tight, lz, ...

State rec(string &S, int idx, int tight, int lz, /*CustomParams*/) {
    // 1. BASE CASE
    if (idx == S.size()) {
        return {1, 0}; 
        // count = 1 (found 1 valid number)
        // value = 0 (base value is 0, unless checking a specific property of the whole number)
    }

    // 2. MEMOIZATION
    if (dp[idx][tight][lz][...].count != -1) return dp[idx][tight][lz][...];

    long long total_count = 0;
    long long total_value = 0;
    int limit = tight ? (S[idx] - '0') : 9;

    for (int digit = 0; digit <= limit; digit++) {
        // 3. TRANSITION LOGIC
        int new_tight = tight && (digit == limit);
        int new_lz = lz && (digit == 0);
        
        // Update your custom constraints (e.g., prev_digit, mask)
        // int new_custom = ... 

        // 4. RECURSIVE CALL
        State sub = rec(S, idx + 1, new_tight, new_lz, new_custom);

        // 5. AGGREGATION (The "Knapsack" Math)
        
        // A. Accumulate the counts from children
        total_count += sub.count;

        // B. Accumulate the values from children
        total_value += sub.value;

        // C. Add MY contribution
        // Calculate what the current 'digit' adds to the answer
        long long current_contribution = 0;
        
        // --- LOGIC BLOCK STARTS ---
        // Example: If counting '1's: if(digit == 1) current_contribution = 1;
        // Example: If Sum of Digits: current_contribution = digit;
        // --- LOGIC BLOCK ENDS ---

        // Multiply my contribution by the number of valid paths in the child
        total_value += (current_contribution * sub.count);
    }

    return dp[idx][tight][lz][...] = {total_count, total_value};
}