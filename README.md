# Matching Nuts and Bolts
A solution to the Nuts &amp; Bolts problem, otherwise known as the Lock &amp; Key problem, implemented in C++. The program sorts a given nuts and bolts array such that nuts[i] == bolts[i]   for each i = 0, ..., nuts.size()-1 within O(nlogn) time.

The implementation works under the assumptions that:
- The input arrays are of the same size
- For every nut n in nuts there is a bolt b in bolts with n == b and likewise for every bolt b in bolts there is a nut n in nuts with b == n.
- There can be multiple nuts and bolts of the same size in the input vector.
