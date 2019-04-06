//
// Created by Zoe on 06/04/2019.
//

#include <string>

#ifndef ANGRYNERDS_LEVEL_H
#  define ANGRYNERDS_LEVEL_H

const int MAX_BIRD_NUM = 10;
const int MAX_PIG_NUM = 10;
const int MAX_BLOCK_NUM = 20;

struct Level
{
  Level() = default;

  bool load(std::string file_name);

  int bird_num = 0;
  int pig_num = 0;
  int block_num = 0;

  float pig_positions[MAX_PIG_NUM][2];
  float block_positions[MAX_BLOCK_NUM][2];
  int block_sizes[MAX_BLOCK_NUM][2];
};

#endif // ANGRYNERDS_LEVEL_H
