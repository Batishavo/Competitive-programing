class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int resultado = 0;
    
        // Iterar a través de cada bit
        for (int i = 0; i < 32; ++i) {
            int sumaBits = 0;
            
            // Contar la cantidad de unos en la posición i
            for (int num : nums) {
                sumaBits += (num >> i) & 1;
            }
            //cout<<"suma :"<<sumaBits<<" pos :"<<i<<" que evalua: "<<((sumaBits % 3) << i)<<endl;
            // El bit del número único es la suma de bits modulo 3
            resultado |= (sumaBits % 3) << i;
        }
    
        return resultado;
    }
};