import numpy as np
import math

#Time
time=0.0
time_sampling=1e-4

#Motion
position=0
velocity=0
acceleration=0
force=0

#For Intefgration with Tastin Transformation
velocity_z1=0
acceleration_z1=0

#Environment
env_k=3400
env_d=2.35
env_m=1.3

#Input and Sensor
force_ref=0
position_get=0

#simulator
sim_loop=100

#make data set
f=open("b.dat","w")
while time <= 50:
    force_ref=10.0*math.sin(5.0*time*time) if time>0.1 else 0.0
    force=force_ref+np.random.normal(0.0, 0.001)
    for i in range(sim_loop):
        #Position
        position+=(velocity+velocity_z1)*time_sampling/sim_loop/2.0 
        velocity_z1=velocity
        #Velocity
        velocity+=(acceleration+acceleration_z1)*time_sampling/sim_loop/2.0
        acceleration_z1=acceleration
        #Acceleration
        acceleration=(-env_k*position-velocity*env_d+force)/env_m
    position_get=position+np.random.normal(0.0, 50e-9)
    result = "{:.7f} {:.7f} {:.7f}\n".format(time, force_ref,position_get)
    f.write(result)
    time+=time_sampling
f.close() 

        

