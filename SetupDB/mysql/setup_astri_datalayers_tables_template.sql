CREATE DATABASE IF NOT EXISTS __DBNAME__;

USE __DBNAME__;

CREATE TABLE IF NOT EXISTS evt3 (
                                        evtid INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
                                        eventidfits INTEGER,
                                        observationid INTEGER UNSIGNED,
                                        datarepositoryid INTEGER UNSIGNED,
                                        ra_deg DOUBLE,
                                        dec_deg DOUBLE,
                                        energy DOUBLE,
                                        detx DOUBLE,
                                        dety DOUBLE,
                                        alt DOUBLE,
                                        az DOUBLE,
                                        gammaness DOUBLE,
                                        status INTEGER,
                                        timerealtt DOUBLE,
                                        insert_time INTEGER UNSIGNED
                                      );



CREATE TABLE IF NOT EXISTS evt2b (
                                       evtid INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
                                       observationid INTEGER UNSIGNED,
                                       datarepositoryid INTEGER UNSIGNED,
                                       status INTEGER UNSIGNED,
                                       gps_st FLOAT,
                                       time_ut  DATETIME,
                                       evt_time_s FLOAT,
                                       evt_time_ns FLOAT,
                                       zd FLOAT,
                                       az FLOAT,
                                       src_pos_x FLOAT,
                                       src_pos_y FLOAT,
                                       img_stvalid FLOAT,
                                       img_stxdir FLOAT,
                                       img_stydir FLOAT,
                                       img_stxcore FLOAT,
                                       img_stycore FLOAT,
                                       img_stmaxh  FLOAT,
                                       img_min_dir FLOAT,
                                       img_min_core FLOAT,
                                       img_min_maxh FLOAT,
                                       st_imp_par FLOAT,
                                       g_gammaness FLOAT,
                                       g_est_en FLOAT,
                                       xdisp FLOAT,
                                       ydisp FLOAT,
                                       ra FLOAT,
                                       `dec` FLOAT,
                                       evtnum FLOAT,
                                       ntrigtel FLOAT,
                                       n_used_tel FLOAT,
                                       n_used_tel_reco FLOAT
                                    );
