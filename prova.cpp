#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>


// 1. Recursive sequence Algo
int S(int n) {
    if (n == 1) return 10;
    return S(n - 1) + 10;
}
//havia comentado com vc que ha um problema na criacao da funcao geral
//double A(int n) {  
    //if (n == 1) {
        //return 2.0;
    //}
    //return A(n-1) * (1.0 / (n - 1));
//}


int B(int n) {
    if (n == 1) return 1;
    return B(n - 1) + n * n;
}

int P(int n) {
    if (n == 1) return 1;
    return n * n * P(n - 1) + n - 1;
}

int D(int n) {
    if (n == 1) return 3;
    if (n == 2) return 5;
    return (n - 1) * D(n - 1) + (n - 2) * D(n - 2);
}

int W(int n) {
    if (n == 1) return 2;
    if (n == 2) return 5;
    return W(n - 1) * W(n - 2);
}

int T(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return T(n - 1) + 2 * T(n - 2) + 3 * T(n - 3);
}

// 2. Geometric progression
double geometric_progression(double a, double r, int n) {
    if (n == 1) return a;
    return geometric_progression(a, r, n - 1) * r;
}

// 3. Belongs to T
bool belongs_to_T(int x) {
    if (x == 2) {
        return true;
    }
    if (x < 2) {
        return false;
    }
    if (x > 2 && belongs_to_T(x - 3)) {
        return true;
    }
    if (x % 2 == 0 && belongs_to_T(x / 2)) {
        return true;
    }

    return false;
}

// 4. Belongs to M
std::unordered_map<int, bool> cache;

bool belongs_to_M(int n) {
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }

    if (n == 2 || n == 3) {
        cache[n] = true;
        return true;
    }

    for (int i = 2; i < n; i++) {
        if (belongs_to_M(i) && belongs_to_M(n - i)) {
            cache[n] = true;
            return true;
        }
    }

    cache[n] = false;
    return false;
}

// 5. Belongs to S
bool belongs_to_S(const std::string& s) {
    if (s.empty()) {
        return true;
    } else if (s == "a") {
        return true;
    } else if (s.back() == 'b') {
        std::string substring = s.substr(0, s.length() - 1);
        return belongs_to_S(substring);
    } else {
        return false;
    }
}

// 6. Belongs to W
bool belongs_to_W(const std::string& str) {
    if (str.empty()) {
        return true;
    }
    if (str[0] == 'a') {
        size_t pos = str.find('c');
        if (pos == std::string::npos || pos == str.length() - 1) {
            return false;
        }
        return belongs_to_W(str.substr(1, pos - 1)) && belongs_to_W(str.substr(pos + 1));
    } else {
        return false;
    }
}

// 7. Binary sequence
bool has_odd_zeros(std::string string, int count = 0) {
    if (string.empty()) return count % 2 == 1;
    if (string[0] == '0') count++;
    return has_odd_zeros(string.substr(1), count);
}

// 8. S(n)
double sequence_a(int n) {
    return std::pow(3, n - 1);
}

double sequence_b(int n) {
    if (n == 1) {
        return 2.0;
    }
    return sequence_b(n - 1) / 2.0;
}


double sequence_c(int n, double a = 1, double b = 1) {
    if (n == 1) return a;
    if (n == 2) return b;
    return sequence_c(n - 1, b, a + b);
}

int sequence_d(int n, int p, int q) {
    if (n == 1) {
        return p;
    } else if (n % 2 == 0) {
        return p - q * (n / 2);
    } else {
        return p + q * ((n - 1) / 2);
    }
}



// 9. Triangular number
int triangular_number(int n) {
    if (n == 1) return 1;
    return n + triangular_number(n - 1);
}

// 10. Bacteria population
int bacteria_population(int n, int initial_population = 50000) {
    if (n == 1) return initial_population;
    return 3 * bacteria_population(n - 1);
}

int hours_to_exceed(int threshold, int count = 1, int initial_population = 50000) {
    if (bacteria_population(count) > threshold) return count;
    return hours_to_exceed(threshold, count + 1);
}

// 11. Algoritmo recursivo Rotina
std::vector<int> Rotina(std::vector<int> L, int j) {
    if (j == 1) return L;
    int max_index = std::distance(L.begin(), std::max_element(L.begin(), L.begin() + j));
    std::swap(L[max_index], L[j - 1]);
    return Rotina(L, j - 1);
}

int main() {
    // 1. Sequence
    std::cout << "S(5): " << S(5) << std::endl;

    std::cout << "B(5): " << B(5) << std::endl;
    std::cout << "P(5): " << P(5) << std::endl;
    std::cout << "D(5): " << D(5) << std::endl;
    std::cout << "W(5): " << W(5) << std::endl;
    std::cout << "T(5): " << T(5) << std::endl;

    // 2. Geometric progression
    std::cout << "Term 5 of geometric progression with a=2 and r=3: " << geometric_progression(1, 2, 2) << std::endl;

    // 3. Belongs to T
    std::cout << "Does 6 belong to T? " << belongs_to_T(6) << std::endl;
    std::cout << "Does 7 belong to T? " << belongs_to_T(7) << std::endl;
    std::cout << "Does 19 belong to T? " << belongs_to_T(19) << std::endl;
    std::cout << "Does 12 belong to T? " << belongs_to_T(12) << std::endl;



    // 4. Belongs to M 6, 9, 16, 21, 26, 54, 72, 218};

  std::cout << "Does 6 belong to M? " << belongs_to_M(6) << std::endl;
  std::cout << "Does 9 belong to M? " << belongs_to_M(9) << std::endl;
  std::cout << "Does 16 belong to M? " << belongs_to_M(16) << std::endl;
  std::cout << "Does 21 belong to M? " << belongs_to_M(21) << std::endl;
  std::cout << "Does 26 belong to M? " << belongs_to_M(26) << std::endl;
  std::cout << "Does 54 belong to M? " << belongs_to_M(54) << std::endl;
  std::cout << "Does 72 belong to M? " << belongs_to_M(72) << std::endl;
  std::cout << "Does 218 belong to M? " << belongs_to_M(218) << std::endl;

    // 5. Belongs to S
    std::cout << "Does 'a' belong to S? " << belongs_to_S("a") << std::endl;
    std::cout << "Does 'ab' belong to S? " << belongs_to_S("ab") << std::endl;
    std::cout << "Does 'aba' belong to S? " << belongs_to_S("aba") << std::endl;
    std::cout << "Does 'aaab' belong to S? " << belongs_to_S("aaab") << std::endl;
    std::cout << "Does 'bbbbb' belong to S? " << belongs_to_S("bbbbb") << std::endl;

    // 6. Belongs to W
    std::cout << "Does 'a(b)c' belong to W? " << belongs_to_W("a(b)c") << std::endl;
    std::cout << "Does 'a(a(b)c)c' belong to W? " << belongs_to_W("a(a(b)c)c") << std::endl;
    std::cout << "Does 'a(abc)c' belong to W? " << belongs_to_W("a(abc)c") << std::endl;
    std::cout << "Does 'a(a(a(a)c)c)c' belong to W? " << belongs_to_W("a(a(a(a)c)c)c") << std::endl;
    std::cout << "Does 'a(aacc)c' belong to W? " << belongs_to_W("a(aacc)c") << std::endl;

    // 7. Binary sequence
    std::cout << "Does '1001' have odd zeros? " << has_odd_zeros("1001") << std::endl;

    // 8. S(n)
    std::cout << "sequence_a(5): " << sequence_a(5) << std::endl;
    std::cout << "sequence_b(5): " << sequence_b(5) << std::endl;
    std::cout << "sequence_c(5): " << sequence_c(5) << std::endl;
    std::cout << "sequence_d(5): " << sequence_d(5, 1, 1) << std::endl;

    // 9. Triangular numbers
    std::cout << "5th triangular number: " << triangular_number(5) << std::endl;

    // 10. Bacteria Population
    std::cout << "Bacteria population after 5 hours: " << bacteria_population(5) << std::endl;
    std::cout << "Hours for bacteria to exceed 200,000: " << hours_to_exceed(200000) << std::endl;
//hora 1 = 50000
    // 11. Routine
    std::vector<int> list = {3, 7, 4, 2, 6};
    list = Rotina(list, list.size());
    std::cout << "Sorted list using Routine: ";
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}