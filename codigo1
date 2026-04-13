use rand::RngExt;
use std::thread;
use std::time::Duration;

fn main() {

    let mut speedMotorA: i32 = 0;
    let mut speedMotorB: i32 = 0;
    
    let mut rng = rand::rng();
    let mut sensor0: i32 = rng.random();
    let mut sensor1: i32 = rng.random();
    let mut sensor2: i32 = rng.random();
    let mut sensor3: i32 = rng.random();

    let mut sensor = [sensor0,sensor1,sensor2,sensor3];
    
        for k in 0..4{
            sensor[k] = sensor[k] / 100;
            if sensor[k] <= 0 {sensor[k] = 0;}
            if sensor[k] >= 256  {sensor[k] = 256;}
        }
    
    for i in 0..20{

        let mut nextSpeedMotorA: i32 = 0;
        let mut nextSpeedMotorB: i32 = 0;

        if(sensor[0] >= 100 && sensor[1] >=100){sensor[2] = sensor[2]/10; sensor[3] = sensor[3]/10;}
        if(sensor[2] >= 100 && sensor[3] >= 100){sensor[0] = sensor[2]/10; sensor[1] = sensor[3]/10;}
        if(sensor[1] >= 100 && sensor[2] >= 100){sensor[0] = sensor[2]/10; sensor[3] = sensor[3]/10;}
        
        sensor[0] = sensor[0] + speedMotorB;
        sensor[1] = sensor[1] + speedMotorB*2;
        sensor[2] = sensor[2] + speedMotorA*2;
        sensor[3] = sensor[3] + speedMotorA;
        
        for k in 0..4{
            if sensor[k] <= 0 {sensor[k] = 0;}
            if sensor[k] >= 256  {sensor[k] = 256;}
        }
        
        nextSpeedMotorA = sensor[0]/2 + sensor[1]/5 - sensor[2]/5 - sensor[3]/2;
        nextSpeedMotorB = sensor[3]/2 + sensor[2]/5 - sensor[1]/5 - sensor[0]/2;

            
        print!("sensor 0: {} || ",sensor[0]); print!("sensor 1: {} || ", sensor[1]);print!("sensor 2: {} || ", sensor[2]);
        println!("sensor 3: {}", sensor[3]); println!("prox. vel. motor A = {nextSpeedMotorA} || prox. vel. motor B = {nextSpeedMotorB}");
        println!("---------------------------------------------------------------------");
        speedMotorA = nextSpeedMotorA;
        speedMotorB = nextSpeedMotorB;
        thread::sleep(Duration::from_secs(2));
    }
}
