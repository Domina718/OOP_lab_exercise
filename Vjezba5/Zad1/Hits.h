#pragma once
#include "Target.h"
#include "Weapon.h"

Target* generate_targets_and_shooter(Weapon& shooter, int& n);
int hits(Target* targets, Weapon shooter, int n);
double min(double a, double b);
double max(double a, double b);