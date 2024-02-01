#include <iostream>
#include <sstream>

#include "cell_operator.h"

// OR   -> fc
// AND  -> c0
// XOR  -> 3c

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        std::cout << "Usage: ./ca [hex-code(6)]\n";
        return 0;
    }

    std::string_view strLhs(argv[1], 2);
    std::string_view strRhs(argv[1] + 2, 2);
    std::string_view strRule(argv[1] + 4, 2);

    unsigned int lhs{};
    unsigned int rhs{};
    unsigned int rule{};

    std::stringstream ss;
    ss << std::hex << strLhs << ' ' << strRhs << ' ' << strRule;
    ss >> lhs >> rhs >> rule;

    std::cout << "--== Read ==--\n";
    std::cout << "LHS:\t" << strLhs << " -> " << lhs << '\n';
    std::cout << "RHS:\t" << strRhs << " -> " << rhs << '\n';
    std::cout << "Rule:\t" << strRule << " -> " << rule << '\n';

    CellOperator<8> cellOp(rule);

    cellOp(lhs, rhs);

    return 0;
}


