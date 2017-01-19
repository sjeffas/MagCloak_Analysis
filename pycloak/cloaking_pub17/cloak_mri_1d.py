import os
import sys

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from matplotlib import cm


def comparescans( figname, figtitle, datafiles, datanames ):

    if ( len( datafiles ) != len( datanames ) ):
        print ("ERROR: Mismatch length datafiles and datanames. Exit.")
        sys.exit(1)

    # create figure
    fig, ax = plt.subplots()

    # first: plot lines for nominal fields
    for i, (dfile, dname) in enumerate( zip( datafiles, datanames ) ):
        print( dfile, dname )
        data = pd.read_csv(dfile, comment='#')
        
        ax.axhline( abs(data['B2']).mean() , color='grey' , linestyle='--')
        
    # second: plot field map data
    for i, (dfile, dname) in enumerate( zip( datafiles, datanames ) ):
        print( dfile, dname )
        data = pd.read_csv(dfile, comment='#')
        ax.plot( data['x'], abs(data['B3']), marker='o', label=dname) #color='b'

        # fill areas between curves and reference value
        #Bnominal = abs(data['B2']).mean()
        #ax.fill_between( data['x'], abs(data['B3']), Bnominal)


    # plot cosmetics: set axis parameters
    ax.set_title(figtitle)
    ax.set_xlabel('x-position (mm)')
    #ax.set_xlim(-12000, 12000)
    ax.set_ylabel('B (mT)')
    #ax.set_ylim(0,500)

    # add legend
    ax.legend(loc = 'lower right')

    plt.savefig(figname)
    plt.show()

# /// END def comparescans ///


if __name__ == '__main__':

    # Compare SC+FM and SC only at 450 mT
    comparescans( "plots/cloak_mri_450mT_1d.png" ,
                  "Cloaking at 0.45 T (field measured in front of prototype)",
                  ["data-calib/DATA_MegaVIEW/DataFile_2016-12-09_12-12-19.csv",
                   "data-calib/DATA_MegaVIEW/DataFile_2016-12-09_15-06-03.csv" ],
                  ["cloak",
                   "sc shield"])

    # Compare SC+FM and SC only at 500 mT
    comparescans( "plots/cloak_mri_500mT_1d.png" ,
                  "Cloaking at 0.50 T (field measured in front of prototype)",
                  ["data-calib/DATA_MegaVIEW/DataFile_2016-12-09_13-32-08.csv",
                   "data-calib/DATA_MegaVIEW/DataFile_2016-12-09_15-42-29.csv" ],
                  ["cloak",
                   "sc shield"])
