while(it != mp.end() && it->second <= cnt) {
  // don't delete using it inside erase function
        auto tmp = it++;
        mp.erase(tmp);
    }
