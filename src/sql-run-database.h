#ifndef DELIBERATE_SQL_RUN_DATABASE_H
#define DELIBERATE_SQL_RUN_DATABASE_H

/****************************************************************
 * This file is distributed under the following license:
 *
 * Copyright (C) 2011, Bernd Stramm
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/

#include <QObject>

class QSqlDatabase;

namespace deliberate
{

class SqlRunner;
class SqlRunQuery;

class SqlRunDatabase
{
public:

  void        close ();
  void        deleteLater ();
  SqlRunner  *runner();

  void transaction ();
  void commit ();

private:

  SqlRunDatabase (SqlRunner * r);
  ~SqlRunDatabase ();

  SqlRunner    *theRunner;
  int           openId;
  QSqlDatabase  *sqlDB;
  QString        dbName;

  friend class SqlRunner;

};

} // namespace

#endif
