#pragma once

template <class ContTy>
auto get_as_cycle(ContTy&& container, int index)
{
    while(index < 0)
    {
        index += container.size();
    }

    while(index >= container.size())
    {
        index -= container.size();
    }

    return container[index];
}
