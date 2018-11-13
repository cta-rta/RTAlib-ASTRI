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

#include"RTA_EVT2b_DB.hpp"

RTA_EVT2b_DB::RTA_EVT2b_DB(string database, string configFilePath) : RTA_DL_DB(database, configFilePath) {
  #ifdef DEBUG
  cout << "[RTA_EVT2b_DB] constructor starts!" << endl;
  #endif
};


int RTA_EVT2b_DB :: insertEvent(
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
                                  string observationid,
                                  string datarepositoryid,
                                  string status,
                                  bool last) {

  EVTbase * evt2b = new EVT2b(
                                 gps_st,
                                 time_ut ,
                                 evt_time_s,
                                 evt_time_ns,
                                 zd,
                                 az,
                                 src_pos_x,
                                 src_pos_y,
                                 img_stvalid,
                                 img_stxdir,
                                 img_stydir,
                                 img_stxcore,
                                 img_stycore,
                                 img_stmaxh ,
                                 img_min_dir,
                                 img_min_core,
                                 img_min_maxh,
                                 st_imp_par,
                                 g_gammaness,
                                 g_est_en,
                                 xdisp,
                                 ydisp,
                                 ra,
                                 dec,
                                 evtnum,
                                 ntrigtel,
                                 n_used_tel,
                                 n_used_tel_reco,
                                 observationid,
                                 datarepositoryid,
                                 status,
                                 false
                              );

  commit = _insertEvent(evt2b);

  return commit;
}
