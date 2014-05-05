/**
 * This file is part of the "recommendify" project
 *   Copyright (c) 2014 Paul Asmuth <paul@paulasmuth.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef _RECOMMENDIFY_USERRECOMMENDER_H
#define _RECOMMENDIFY_USERRECOMMENDER_H

#include <stdlib.h>
#include <stdint.h>
#include <vector>
#include "itemset.h"
#include "rankeditemlist.h"

namespace recommendify {

/**
 * A user recommender generates personalized recommendations from binary
 * user->item ratings
 *
 * The input data is added by calling addPreferenceSet() repeatedly and must be
 * in the form of 'preference sets', i.e. sets of items that have been viewed/
 * bought/clicked by the same user (another way to look at preference sets is
 * as sparse binary feature/rating vectors)
 *
 * A user recommender supports only one type of query getRecommendations() which
 * returns a ranked list of items similar to the query point. The query point is
 * also also a preference set (the set of items which the user for which the 
 * recommendation is to be made viewed/bought/clicked).
 *
 * This is an abstract base class. Currently implemented subclasses are:
 *
 *   - MinHashRecommender
 *
 */
class UserRecommender {
public:

  UserRecommender(UserRecommender& copy) = delete;

  /**
   * Add a preference set to the recommender
   */
  virtual void addPreferenceSet(const ItemSet& preference_set);

  /**
   * Retrieve a list of up to max_items ranked items most similar to the query
   * point and return them into the provided ranked item list
   */
  virtual void getRecommendations(
      const ItemSet& query_point,
      size_t max_items,
      RankedItemList& result) const;

};

}
#endif
