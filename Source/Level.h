//
// Created by Zoe on 06/04/2019.
//

#ifndef ANGRYNERDS_LEVEL_H
#define ANGRYNERDS_LEVEL_H

#include "GameConstants.h"
#include <string>
struct Level
{
 public:
  Level() = default;

  bool load(std::string file_name);

  int bird_num = 0;
  int pig_num = 0;
  int block_num = 0;

  float pig_positions[SETTINGS::MAX_PIG_NUM][2];
  float block_positions[SETTINGS::MAX_BLOCK_NUM][2];
  int block_sizes[SETTINGS::MAX_BLOCK_NUM][2];
};

#endif // ANGRYNERDS_LEVEL_H
