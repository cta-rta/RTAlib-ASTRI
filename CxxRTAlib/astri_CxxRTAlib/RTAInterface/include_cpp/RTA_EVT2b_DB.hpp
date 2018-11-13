/*
 ==========================================================================

 Copyright (C) 2018 Leonardo Baroncelli
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ==========================================================================
*/

#ifndef RTA_EVT2b_DB_H
#define RTA_EVT2b_DB_H

#include "RTA_DL_DB.hpp"
#include "EVT2b.hpp"

class RTA_EVT2b_DB : public RTA_DL_DB {

  public:

    RTA_EVT2b_DB(string database, string configFilePath="./");

    int insertEvent(
                      string gps_st,
                      string time_ut,
                      string evt_time_s,
                      string evt_time_ns,
                      string zd,
                      string az,
                      string src_pos_x,
                      string src_pos_y,
                      string img_stvalid,
                      string img_stxdir,
                      string img_stydir,
                      string img_stxcore,
                      string img_stycore,
                      string img_stmaxh,
                      string img_min_dir,
                      string img_min_core,
                      string img_min_maxh,
                      string st_imp_par,
                      string g_gammaness,
                      string g_est_en,
                      string xdisp,
                      string ydisp,
                      string ra,
                      string dec,
                      string evtnum,
                      string ntrigtel,
                      string n_used_tel,
                      string n_used_tel_reco,
                      string observationid = "1",
                      string datarepositoryid = "1",
                      string status = "1",
                      bool last = false
                    );

    int commit = 0;

};

#endif
