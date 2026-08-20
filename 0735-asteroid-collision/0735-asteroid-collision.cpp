class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // We use a vector as a stack.
        // st.back() = top of our stack.
        vector<int> st;


        // Go through every asteroid one by one.
        for (int a : asteroids) {

            // 'a' = current asteroid.
            //
            // Collision is possible ONLY when:
            //
            // 1. Stack is not empty
            // 2. Top asteroid is moving RIGHT (+)
            // 3. Current asteroid is moving LEFT (-)
            //
            // Example:
            //
            //     10  →    ←  5
            //                 💥
            //
            // st.back() > 0  → stack asteroid goes RIGHT
            // a < 0          → current asteroid goes LEFT
            while (!st.empty() && st.back() > 0 && a < 0) {


                // -----------------------------------------
                // CASE 1: CURRENT ASTEROID IS BIGGER
                // -----------------------------------------
                //
                // Example:
                //
                //      5  →    ←  10
                //
                // Stack asteroid size = 5
                // Current asteroid size = 10
                //
                // Current asteroid is negative, so:
                //
                // a = -10
                // -a = 10
                //
                // Therefore:
                //
                //      5 < 10
                //
                // The stack asteroid will explode.
                if (st.back() < -a) {

                    // Remove the smaller asteroid
                    // from the top of the stack.
                    //
                    // Example:
                    //
                    // Stack = [5]
                    //
                    // After pop:
                    //
                    // Stack = []
                    //
                    // IMPORTANT:
                    // Current asteroid is STILL ALIVE.
                    // So the while loop will check it
                    // against the next asteroid in the stack.
                    st.pop_back();
                }


                // -----------------------------------------
                // CASE 2: BOTH ASTEROIDS ARE SAME SIZE
                // -----------------------------------------
                //
                // Example:
                //
                //      5  →    ←  5
                //
                // Both have size 5.
                //
                // According to the problem:
                // If both are the same size,
                // BOTH explode.
                else if (st.back() == -a) {

                    // Remove the stack asteroid.
                    //
                    // Example:
                    //
                    // Stack = [5]
                    //
                    // 5 explodes 💥
                    //
                    // Stack = []
                    st.pop_back();


                    // Current asteroid also explodes.
                    //
                    // We use a = 0 to represent:
                    //
                    // "Current asteroid is destroyed."
                    //
                    // Example:
                    //
                    // 5 →    ← -5
                    //
                    // Stack 5 → 💥
                    // Current -5 → 💥
                    a = 0;


                    // Both asteroids are gone,
                    // so there is no need to continue
                    // checking collisions for this asteroid.
                    break;
                }


                // -----------------------------------------
                // CASE 3: STACK ASTEROID IS BIGGER
                // -----------------------------------------
                //
                // Example:
                //
                //      10  →    ←  5
                //
                // Stack asteroid size = 10
                // Current asteroid size = 5
                //
                // Therefore:
                //
                //      10 > 5
                //
                // The current asteroid explodes.
                else {

                    // Current asteroid is destroyed.
                    //
                    // Example:
                    //
                    // 10 →    ← 5
                    //             💥
                    //
                    // We represent the destroyed
                    // current asteroid using 0.
                    a = 0;


                    // Current asteroid is already destroyed,
                    // so stop checking collisions.
                    break;
                }
            }


            // -----------------------------------------
            // ADD CURRENT ASTEROID IF IT SURVIVED
            // -----------------------------------------
            //
            // If a != 0, it means:
            //
            // Current asteroid is still alive.
            //
            // So we put it into the stack.
            //
            // Example:
            //
            // a = 10
            // Stack = [5]
            //
            // No collision or 10 survived.
            //
            // Stack becomes:
            //
            // [5, 10]
            if (a != 0) {
                st.push_back(a);
            }
        }


        // The stack now contains all asteroids
        // that survived after every collision.
        //
        // Example:
        //
        // Input:
        // [5, 10, -5]
        //
        // Final stack:
        // [5, 10]
        //
        // Therefore return the stack.
        return st;
    }
};