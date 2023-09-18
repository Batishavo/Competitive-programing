/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    
    let n   = gas.length;
    
    let total_gas=0;
    let total_cost=0;

    gas.forEach((num) =>{
        total_gas+=num;
    });
    cost.forEach(num=>{
        total_cost+=num;
    });

    if(total_gas<total_cost){
        return -1;
    }    

    ////////////////
    let current_gas=0;
    let pos = 0;
    for(let i=0;i<n;i++){
        current_gas+=gas[i]-cost[i];
        if(current_gas<0){
            pos=i+1;
            current_gas=0;
        }
        //console.log(current_gas,pos);
    }

    return pos;
};