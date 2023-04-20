def merge_lists(nums1, m, nums2, n):
   # Tu código aquí
   apuntador1=m-1
   apuntador2=n-1
   apuntador3=n+m-1
   while apuntador3!=-1:
      if apuntador1==-1:
         nums1[apuntador3]=nums2[apuntador2]
         apuntador2=apuntador2-1
      elif apuntador2==-1:
         nums1[apuntador3]=nums1[apuntador1]
         apuntador1=apuntador1-1
      else:
         if nums1[apuntador1] > nums2[apuntador2]:
            nums1[apuntador3]=nums1[apuntador1]
            apuntador1=apuntador1-1
            
         else:
            nums1[apuntador3]=nums2[apuntador2]
            apuntador2=apuntador2-1
      
      apuntador3=apuntador3-1

   return nums1

# Arrays de prueba 1
nums1 = [1,2,3,0,0,0]
m = 3
nums2 = [2,5,6]
n = 3
response = merge_lists(nums1, m, nums2, n)
print(response)

# Arrays de prueba 2
nums1 = [1,2,3,0,0,0,0]
m = 3
nums2 = [-4,2,3,9]
n = 4
response = merge_lists(nums1, m, nums2, n)
print(response)