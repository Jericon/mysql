/* Copyright (C) 2003 MySQL AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifndef DIH_STARTTAB__HPP
#define DIH_STARTTAB__HPP

#include "SignalData.hpp"

class DihStartTabReq {
  /**
   * Sender(s)
   */
  friend class Dbdict;

  /**
   * Receiver(s)
   */
  friend class Dbdih;
public:
  STATIC_CONST( HeaderLength = 3 );
  
private:
  
  Uint32 senderRef;
  Uint32 senderData;
  Uint32 noOfTables;
  
  struct {
    Uint32 tableId;
    Uint32 schemaVersion;
  } tables[10];
};

class DihStartTabConf {
  /**
   * Sender(s)
   */
  friend class Dbdih;
  
  /**
   * Receiver(s)
   */
  friend class Dbdict;
public:
  STATIC_CONST( SignalLength = 2 );
  
private:
  Uint32 senderRef;
  Uint32 senderData;
};

#endif
