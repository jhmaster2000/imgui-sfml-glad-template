#include <numbers>
#include <cmath>

inline float degToRad(float deg) { return (deg * std::numbers::pi) / 180.0f; }
inline float radToDeg(float rad) { return (rad * 180.0f) / std::numbers::pi; }
