#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include "IMachine.h"
#include "Wasmachine.h"
#include "Dryer.h"
#include "Steamer.h"
#include "Centrifuge.h"

class MachineFactory
 {
 public:
     static IMachine *NewMachine(const std::string &name);
 };
