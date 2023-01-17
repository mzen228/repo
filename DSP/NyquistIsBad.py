# -*- coding: utf-8 -*-
"""
Created on Wed Nov 16 18:27:39 2022

Illustrates how sampling at the Nyqusit rate can fail to 
adequately capture a signal.  A better choice for minimum
sampling frequency is 5X the signal's highest frequency component. 

@author: mxz50
"""

import numpy as np
from matplotlib import pyplot as plt 

def main():
    Fs=1000
    t_res = 1/Fs
    t=np.arange(0,1,t_res)
    N=len(t)
    f = 10
    x=np.sin(2*np.pi*t*f)
    
    # sampling rates
    sample_rates = [10,20,50,100]
    plots=[(0,0),(0,1),(1,0),(1,1)]
    
    for j in range(len(sample_rates)):
        # print(rate)
        T=1/sample_rates[j]
        midx=np.zeros(sample_rates[j],dtype=int)
        mtime=np.arange(0,1,1/sample_rates[j])
        for i in range(sample_rates[j]):
            midx[i]=np.argmin(abs(mtime[i]-t))
        
        plt.subplot2grid((2,2),plots[j])
        plt.stem(t[midx],x[midx])
        plt.plot(t,x,'r')
        plt.title(f"Sampled at {sample_rates[j]/f}")
        plt.tight_layout()
        plt.xlim(0,.3)
    plt.show()
        
main()