# -*- coding: utf-8 -*-
"""
Created on Wed Nov 16 18:27:39 2022

@author: mxz50
"""

import numpy as np
from matplotlib import pyplot as plt 

def main():
    srate=1000
    t=np.arange(0,1,1/srate)
    npnts=len(t)
    f=10
    signal=np.sin(2*np.pi*t*f)
    
    # measurement rates
    srates = [10,20,50,100]
    # srates=[15]
    plots=[(0,0),(0,1),(1,0),(1,1)]
    
    for j in range(len(srates)):
        # print(rate)
        T=1/srates[j]
        midx=np.zeros(srates[j],dtype=int)
        mtime=np.arange(0,1,1/srates[j])
        for i in range(srates[j]):
            midx[i]=np.argmin(abs(mtime[i]-t))
        
        plt.subplot2grid((2,2),plots[j])
        plt.stem(t[midx],signal[midx])
        plt.plot(t,signal,'r')
        plt.title(f"Sampled at {srates[j]/f}")
        plt.tight_layout()
        plt.xlim(0,.3)
        
main()