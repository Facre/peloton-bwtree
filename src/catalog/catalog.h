/*-------------------------------------------------------------------------
 *
 * catalog.h
 * file description
 *
 * Copyright(c) 2015, CMU
 *
 * /n-store/src/catalog/catalog.h
 *
 *-------------------------------------------------------------------------
 */

#pragma once

#include "catalog/database.h"
#include <iostream>

namespace nstore {
namespace catalog {

//===--------------------------------------------------------------------===//
// Catalog
//===--------------------------------------------------------------------===//

class Catalog {

 public:

  // Singleton
  static Catalog& GetInstance();

  // create default db
  Catalog(){
    Database* db = new Database("default");
    databases.push_back(db);
  }

  bool AddDatabase(Database* db);
  Database* GetDatabase(const std::string &db_name) const;
  bool RemoveDatabase(const std::string &db_name);

  // Get a string representation of this catalog
  friend std::ostream& operator<<(std::ostream& os, const Catalog& catalog);

 private:

  // list of databases in catalog
  std::vector<Database*> databases;

};

} // End catalog namespace
} // End nstore namespace