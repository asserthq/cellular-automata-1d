#pragma once
#include <bitset>

#include "cycle.h"

template<size_t T>
using LineType = std::bitset<T>;

template<size_t N>
class CellAutomata
{
public:
    CellAutomata(LineType<N> initLine, std::bitset<8> rule)
        : m_line(initLine), m_rule(rule)
    {}

    LineType<N> Next()
    {
        LineType<N> nextLine{};

        for(auto i = 0; i < m_line.size(); ++i)
        {
            std::bitset<3> triad{};
            triad[0] = get_as_cycle(m_line, i - 1);
            triad[1] = get_as_cycle(m_line, i);
            triad[2] = get_as_cycle(m_line, i + 1);

            nextLine[i] = m_rule[triad.to_ulong()] ? 1 : 0;
        }

        swap(m_line, nextLine);
        return m_line;
    }

    LineType<N> State() const { return m_line; }

private:
    LineType<N> m_line;
    std::bitset<8> m_rule;
};