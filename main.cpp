#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;


struct IntConstants {
    public:
        static const int ZERO = 0;
        static const int ONE = 1;
        static const int TWO = 2;
        static const int THREE = 3;
        static const int FOUR = 4;
        static const int FIVE = 5;
        static const int SIX = 6;
        static const int SEVEN = 7;
        static const int EIGHT = 8;
        static const int NINE = 9;
};

struct FloatConstants {
    public:
        static constexpr double ZERO = 0.0;
        static constexpr double ONE = 1.0;
        static constexpr double TWO = 2.0;
        static constexpr double THREE = 3.0;
        static constexpr double FOUR = 4.0;
        static constexpr double FIVE = 5.0;
        static constexpr double SIX = 6.0;
        static constexpr double SEVEN = 7.0;
        static constexpr double EIGHT = 8.0;
        static constexpr double NINE = 9.0;
};

struct Number {
    double value;
};

struct NumberConstants {
    static const Number ZERO;
    static const Number ONE;
    static const Number TWO;
    static const Number THREE;
    static const Number FOUR;
    static const Number FIVE;
    static const Number SIX;
    static const Number SEVEN;
    static const Number EIGHT;
    static const Number NINE;
};

const Number NumberConstants::ZERO = {0.0};
const Number NumberConstants::ONE = {1.0};
const Number NumberConstants::TWO = {2.0};
const Number NumberConstants::THREE = {3.0};
const Number NumberConstants::FOUR = {4.0};
const Number NumberConstants::FIVE = {5.0};
const Number NumberConstants::SIX = {6.0};
const Number NumberConstants::SEVEN = {7.0};
const Number NumberConstants::EIGHT = {8.0};
const Number NumberConstants::NINE = {9.0};

struct SolutionTypeConstants {
    static const int NoRoots;
    static const int AnyRoots;
    static const int SingleRoot;
    static const int TwoRoots;
    static const int RepeatedRoots;
    static const int TwoRootsComplex;
};

const int SolutionTypeConstants::NoRoots = 0;
const int SolutionTypeConstants::AnyRoots = 1;
const int SolutionTypeConstants::SingleRoot = 2;
const int SolutionTypeConstants::TwoRoots = 3;
const int SolutionTypeConstants::RepeatedRoots = 4;
const int SolutionTypeConstants::TwoRootsComplex = 5;

struct OutputConstants {
    static constexpr const char* SOLUTION_HEADER = "Решение уравнения:";
    static constexpr const char* NO_ROOTS_MSG = "Уравнение не имеет корней.";
    static constexpr const char* ANY_ROOTS_MSG = "Уравнение имеет бесконечно много решений (любое x).";
    static constexpr const char* SINGLE_ROOT_HEADER = "Уравнение имеет один действительный корень:";
    static constexpr const char* TWO_ROOTS_HEADER = "Уравнение имеет два различных корня:";
    static constexpr const char* REPEATED_ROOTS_MSG = "Уравнение имеет один кратный действительный корень:";
    static constexpr const char* COMPLEX_ROOTS_MSG = "Уравнение имеет комплексные корни:";
    static constexpr const char* UNKNOWN_SOLUTION_MSG = "Неизвестный тип решения.";
    static constexpr const char* X1_LABEL = "x1 = ";
    static constexpr const char* X2_LABEL = "x2 = ";
    static constexpr const char* X_LABEL = "x = ";
    static constexpr const char* REPEATED_ROOT_FORMAT = "x1 = x2 = ";
    static constexpr const char* IMAGINARY_PART_FORMAT = "+";
    static constexpr const char* IMAGINARY_UNIT = "i";
    static constexpr const char* END_MESSAGE = "\n";
    static constexpr const char* SPACE = " ";
    static constexpr const char* ERR = "Error: ";
};

struct ErrorConstants {
    static constexpr const char* NoError = "NO_ERROR";
};

struct ComplexNum {
    double real;
    double imag;
};

ComplexNum create_compl(double real = FloatConstants::ZERO, double imag = FloatConstants::ZERO) {
    ComplexNum complex;
    complex.real = real;
    complex.imag = imag;
    return complex;
}

ComplexNum add_compl(const ComplexNum& first, const ComplexNum& second) {
    ComplexNum result;
    result.real = first.real + second.real;
    result.imag = first.imag + second.imag;
    return result;
}

ComplexNum sub_compl(const ComplexNum& first, const ComplexNum& second) {
    ComplexNum result;
    result.real = first.real - second.real;
    result.imag = first.imag - second.imag;
    return result;
}

ComplexNum mult_compl(const ComplexNum& first, const ComplexNum& second) {
    ComplexNum result;
    result.real = first.real * second.real - first.imag * second.imag;
    result.imag = first.real * second.imag + first.imag * second.real;
    return result;
}

ComplexNum div_compl(const ComplexNum& first, const ComplexNum& second) {
    ComplexNum result;
    double denominator = second.real * second.real + second.imag * second.imag;
    result.real = (first.real * second.real + first.imag * second.imag) / denominator;
    result.imag = (first.imag * second.real - first.real * second.imag) / denominator;
    return result;
}

ComplexNum compl_sqrt(double num) {
    ComplexNum result = create_compl(FloatConstants::ZERO, sqrt(-num));
    return result;
}

struct InputCoefficients {
    double a;
    double b;
    double c;
};

double get_a(const InputCoefficients& ic) {
    return ic.a;
}

double get_b(const InputCoefficients& ic) {
    return ic.b;
}

double get_c(const InputCoefficients& ic) {
    return ic.c;
}

double get_discriminant(const InputCoefficients& ic){
    return get_b(ic) * get_b(ic) - FloatConstants::FOUR * get_a(ic) * get_c(ic);
}

InputCoefficients set_a(InputCoefficients& ic, double value) {
    ic.a = value;
    return ic;
}

InputCoefficients set_b(InputCoefficients& ic, double value) {
    ic.b = value;
    return ic;
}

InputCoefficients set_c(InputCoefficients& ic, double value) {
    ic.c = value;
    return ic;
}

string input_data() {
    string s;
    cin >> s;
    return s;
}

double interpret_data() {
    return stod(input_data());
}

InputCoefficients transform_input_coefficients() {
    return {interpret_data(), interpret_data(), interpret_data()};
}

InputCoefficients input_coefficients() {
    return transform_input_coefficients();
}

bool is_zero(double value) {
    return fabs(value) < 1e-7;
}

enum SolutionType {
    ANY_ROOTS = SolutionTypeConstants::AnyRoots,
    ONE_ROOT = SolutionTypeConstants::SingleRoot,
    SAME_ROOTS = SolutionTypeConstants::RepeatedRoots,
    REAL_AND_DISTINCT_ROOTS = SolutionTypeConstants::TwoRoots,
    COMPLEX_ROOTS = SolutionTypeConstants::TwoRootsComplex,
    NO_ROOTS = SolutionTypeConstants::NoRoots
};

const vector<string> solutionMessages = {
    OutputConstants::NO_ROOTS_MSG,
    OutputConstants::ANY_ROOTS_MSG,
    OutputConstants::SINGLE_ROOT_HEADER,
    OutputConstants::TWO_ROOTS_HEADER,
    OutputConstants::REPEATED_ROOTS_MSG,
    OutputConstants::COMPLEX_ROOTS_MSG
};

struct Solution {
    ComplexNum x1;
    ComplexNum x2;
    int type;
    string error;
};

Solution createSolution(ComplexNum x1, ComplexNum x2, int type, const string& error = ErrorConstants::NoError) {
    Solution solution;
    solution.x1 = x1;
    solution.x2 = x2;
    solution.type = type;
    solution.error = error;
    return solution;
}

Solution solve_linear_b_zero_c_zero() {
    return createSolution(create_compl(), create_compl(), ANY_ROOTS);
}

Solution solve_linear_b_zero_c_not_zero() {
    return createSolution(create_compl(), create_compl(), NO_ROOTS);
}

Solution solve_linear_b_not_zero_c_zero() {
    return createSolution(create_compl(), create_compl(), ONE_ROOT);
}

Solution solve_linear_b_not_zero_c_not_zero(const InputCoefficients& ic) {
    double x = -get_c(ic) / get_b(ic);
    return createSolution(create_compl(x, FloatConstants::ZERO), create_compl(x, FloatConstants::ZERO), SAME_ROOTS);
}

Solution solve_quadratic_b_zero_c_zero(const InputCoefficients& ic) {
    return createSolution(create_compl(), create_compl(), SAME_ROOTS);
}

Solution solve_quadratic_b_zero_c_not_zero_negative(const InputCoefficients& ic) {
    ComplexNum x1 = create_compl(FloatConstants::ZERO, sqrt(-get_c(ic) / get_a(ic)));
    ComplexNum x2 = create_compl(FloatConstants::ZERO, -sqrt(-get_c(ic) / get_a(ic)));
    return createSolution(x1, x2, COMPLEX_ROOTS);
}

Solution solve_quadratic_b_zero_c_not_zero_positive(const InputCoefficients& ic) {
    double x1 = sqrt(-get_c(ic) / get_a(ic));
    double x2 = -sqrt(-get_c(ic) / get_a(ic));
    return createSolution(create_compl(x1, FloatConstants::ZERO), create_compl(x2, FloatConstants::ZERO), REAL_AND_DISTINCT_ROOTS);
}

Solution solve_quadratic_b_zero_c_not_zero(const InputCoefficients& ic) {
    if (-get_c(ic) / get_a(ic) < FloatConstants::ZERO) {
        return solve_quadratic_b_zero_c_not_zero_negative(ic);
    } else {
        return solve_quadratic_b_zero_c_not_zero_positive(ic);
    }
}

Solution solve_quadratic_b_not_zero_c_zero(const InputCoefficients& ic) {
    ComplexNum x1 = create_compl(FloatConstants::ZERO, FloatConstants::ZERO);
    ComplexNum x2 = create_compl(-get_b(ic) / get_a(ic), FloatConstants::ZERO);
    return createSolution(x1, x2, REAL_AND_DISTINCT_ROOTS);
}

Solution solve_quadratic_b_not_zero_c_not_zero_negative_discriminant(const InputCoefficients& ic, double d) {
    ComplexNum sqrt_d = compl_sqrt(d);
    ComplexNum x1 = div_compl(add_compl(create_compl(-get_b(ic), FloatConstants::ZERO), sqrt_d), 
                             create_compl(FloatConstants::TWO * get_a(ic), FloatConstants::ZERO));
    ComplexNum x2 = div_compl(sub_compl(create_compl(-get_b(ic), FloatConstants::ZERO), sqrt_d), 
                             create_compl(FloatConstants::TWO * get_a(ic), FloatConstants::ZERO));
    return createSolution(x1, x2, COMPLEX_ROOTS);
}

Solution solve_quadratic_b_not_zero_c_not_zero_zero_discriminant(const InputCoefficients& ic) {
    double x = -get_b(ic) / (FloatConstants::TWO * get_a(ic));
    return createSolution(create_compl(x, FloatConstants::ZERO), create_compl(x, FloatConstants::ZERO), SAME_ROOTS);
}

Solution solve_quadratic_b_not_zero_c_not_zero_positive_discriminant(const InputCoefficients& ic) {
    double discriminant = get_discriminant(ic);
    double x1 = (-get_b(ic) + sqrt(discriminant)) / (FloatConstants::TWO * get_a(ic));
    double x2 = (-get_b(ic) - sqrt(discriminant)) / (FloatConstants::TWO * get_a(ic));
    return createSolution(create_compl(x1, FloatConstants::ZERO), create_compl(x2, FloatConstants::ZERO), REAL_AND_DISTINCT_ROOTS);
}

Solution solve_quadratic_b_not_zero_c_not_zero(const InputCoefficients& ic) {
    double discriminant = get_discriminant(ic);
    if (discriminant < FloatConstants::ZERO) {
        return solve_quadratic_b_not_zero_c_not_zero_negative_discriminant(ic, discriminant);
    } else if (is_zero(discriminant)) {
        return solve_quadratic_b_not_zero_c_not_zero_zero_discriminant(ic);
    } else {
        return solve_quadratic_b_not_zero_c_not_zero_positive_discriminant(ic);
    }
}

Solution solve_linear_b_zero(const InputCoefficients& ic) {
    if (is_zero(get_c(ic))) {
        return solve_linear_b_zero_c_zero();
    } else {
        return solve_linear_b_zero_c_not_zero();
    }
}

Solution solve_linear_b_not_zero(const InputCoefficients& ic) {
    if (is_zero(get_c(ic))) {
        return solve_linear_b_not_zero_c_zero();
    } else {
        return solve_linear_b_not_zero_c_not_zero(ic);
    }
}

Solution solve_quadratic_b_zero(const InputCoefficients& ic) {
    if (is_zero(get_c(ic))) {
        return solve_quadratic_b_zero_c_zero(ic);
    } else {
        return solve_quadratic_b_zero_c_not_zero(ic);
    }
}

Solution solve_quadratic_b_not_zero(const InputCoefficients& ic) {
    if (is_zero(get_c(ic))) {
        return solve_quadratic_b_not_zero_c_zero(ic);
    } else {
        return solve_quadratic_b_not_zero_c_not_zero(ic);
    }
}

Solution solve_linear(const InputCoefficients& ic) {
    if (is_zero(get_b(ic))) {
        return solve_linear_b_zero(ic);
    } else {
        return solve_linear_b_not_zero(ic);
    }
}

Solution solve_quadratic(const InputCoefficients& ic) {
    if (is_zero(get_b(ic))) {
        return solve_quadratic_b_zero(ic);
    } else {
        return solve_quadratic_b_not_zero(ic);
    }
}

bool is_linear(const InputCoefficients& ic){
    return is_zero(get_a(ic));
}

Solution solve_equation(const InputCoefficients& ic) {
    if (is_linear(ic)) {
        return solve_linear(ic);
    } else {
        return solve_quadratic(ic);
    }
}

string form_real(double value) {
    return to_string(value);
}

string form_imaginary(double value) {
    string result;
    if (value >= IntConstants::ZERO) {
        result += OutputConstants::IMAGINARY_PART_FORMAT;
    }
    result += to_string(value) + OutputConstants::IMAGINARY_UNIT;
    return result;
}

string format_complex(const ComplexNum& num) {
    if (is_zero(num.imag)) {
        return form_real(num.real);
    } 
    if (is_zero(num.real)) {
        return form_imaginary(num.imag);
    }
    return form_real(num.real) + OutputConstants::SPACE + form_imaginary(num.imag);
}

void out_on_screen(const string& s) {
    cout << s << OutputConstants::END_MESSAGE;
}

void output_error(const Solution& s) {
    out_on_screen(OutputConstants::ERR + s.error);
}

void output_any_roots() {
    out_on_screen(OutputConstants::ANY_ROOTS_MSG);
}

void output_no_roots() {
    out_on_screen(OutputConstants::NO_ROOTS_MSG);
}

void output_single_root(const Solution& s) {
    out_on_screen(string(OutputConstants::SINGLE_ROOT_HEADER) + OutputConstants::SPACE +
                  OutputConstants::X_LABEL + format_complex(s.x1));
}

void output_repeated_roots(const Solution& s) {
    out_on_screen(string(OutputConstants::REPEATED_ROOTS_MSG) + OutputConstants::SPACE +
                  OutputConstants::REPEATED_ROOT_FORMAT + format_complex(s.x1));
}

void output_real_and_distinct_roots(const Solution& s) {
    out_on_screen(OutputConstants::TWO_ROOTS_HEADER);
    out_on_screen(string(OutputConstants::X1_LABEL) + format_complex(s.x1));
    out_on_screen(string(OutputConstants::X2_LABEL) + format_complex(s.x2));
}

void output_complex_roots(const Solution& s) {
    out_on_screen(OutputConstants::COMPLEX_ROOTS_MSG);
    out_on_screen(string(OutputConstants::X1_LABEL) + format_complex(s.x1));
    out_on_screen(string(OutputConstants::X2_LABEL) + format_complex(s.x2));
}

void output_unknown_solution() {
    out_on_screen(OutputConstants::UNKNOWN_SOLUTION_MSG);
}



void output(const Solution& s) {
    out_on_screen(OutputConstants::SOLUTION_HEADER);

    if (s.error != ErrorConstants::NoError) {
        output_error(s); //TODO abst
    }

    switch(s.type) {
        case ANY_ROOTS:
            output_any_roots();
            break;
        case NO_ROOTS:
            output_no_roots();
            break;
        case ONE_ROOT:
            output_single_root(s);
            break;
        case SAME_ROOTS:
            output_repeated_roots(s);
            break;
        case REAL_AND_DISTINCT_ROOTS:
            output_real_and_distinct_roots(s);
            break;
        case COMPLEX_ROOTS:
            output_complex_roots(s);
            break;
        default:
            output_unknown_solution();
    }
}




int main() {
    InputCoefficients ic = input_coefficients();
    Solution s = solve_equation(ic);
    output(s);
    return IntConstants::ZERO;
}