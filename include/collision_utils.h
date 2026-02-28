#pragma once

inline bool aabb_overlap(
    bn::fixed ax, bn::fixed ay, int aw, int ah,
    bn::fixed bx, bn::fixed by, int bw, int bh)
{
    return ax < bx + bw &&
           ax + aw > bx &&
           ay < by + bh &&
           ay + ah > by;
}