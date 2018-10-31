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
                                      eventidfits INTEGER,
                                      observationid INTEGER UNSIGNED,
                                      datarepositoryid INTEGER UNSIGNED

                                    );
