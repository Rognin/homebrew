#pragma once

inline bool aabb_overlap(
    int ax, int ay, int aw, int ah,
    int bx, int by, int bw, int bh)
{
    return ax < bx + bw &&
           ax + aw > bx &&
           ay < by + bh &&
           ay + ah > by;
}