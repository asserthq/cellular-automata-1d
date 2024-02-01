#pragma once
#include <iostream>

#include "cell_automata.h"

template<size_t N>
class CellOperator 
{
public:
    CellOperator(uint8_t rule)
     : m_rule(rule)
    {}

    auto operator()(LineType<N> lhs, LineType<N> rhs)
    {
        LineType<2 * N> temp{};
        for(auto i = 0; i < N; ++i)
        {
            temp[2 * i] = lhs[i];
            temp[2 * i + 1] = rhs[i];
        }

        CellAutomata automata(temp, m_rule);
        temp = automata.Next();

        LineType<N> result{};
        for(auto i = 0; i < N; ++i)
        {
            result[i] = temp[2 * i];
        }

        std::cout << "--== Operator ==--\n";
        std::cout << "Rule: " << m_rule.to_string() << '\n';
        std::cout << "LHS:\t" << lhs.to_string() << '\n';
        std::cout << "RHS:\t" << rhs.to_string() << '\n';
        std::cout << "Result:\t" << result.to_string() << '\n';

        return result;
    }

private:
    std::bitset<8> m_rule;
};