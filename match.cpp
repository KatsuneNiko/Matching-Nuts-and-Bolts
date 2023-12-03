#include <vector>
#include <utility>
#include "nuts_and_bolts.hpp"
#include "match.hpp"

void matchNutsAndBolts(std::vector<Nut>& nuts, std::vector<Bolt>& bolts) {
  // implement your solution here.
  recursiveMatch(nuts, bolts, 0, (int) (nuts.size() - 1));
}

int partitionNuts(std::vector<Nut>& nuts, int low, int high, Bolt pivot){
  int i = low;
  for (int j = low; j < high; j++){
    if(nuts[j] < pivot){
      std::swap(nuts[i], nuts[j]);
      i++;
    }
    // if nuts[high] is already equal to the pivot then there's no reason to swap, and decrementing j 
    // in that case would cause an infinite loop where it keeps swapping j and high over and over
    else if(nuts[j] == pivot && nuts[high] != pivot){
      std::swap(nuts[j], nuts[high]);
      j--;
    }
  }

  std::swap(nuts[i], nuts[high]);

  return i;
}

int partitionBolts(std::vector<Bolt>& bolts, int low, int high, Nut pivot){
  int i = low;
  for (int j = low; j < high; j++){
    if(bolts[j] < pivot){
      std::swap(bolts[i], bolts[j]);
      i++;
    }
    else if(bolts[j] == pivot && bolts[high] != pivot){
      std::swap(bolts[j], bolts[high]);
      j--;
    }
  }

  std::swap(bolts[i], bolts[high]);

  return i;
}

void recursiveMatch(std::vector<Nut>& nuts, std::vector<Bolt>& bolts, int low, int high){
  if (low < high){
    int pivotIndex = partitionNuts(nuts, low, high, bolts[high]);
    partitionBolts(bolts, low, high, nuts[pivotIndex]);

    recursiveMatch(nuts, bolts, low, pivotIndex - 1);
    recursiveMatch(nuts, bolts, pivotIndex + 1, high);
  }
}
