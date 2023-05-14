def twoSum(nums, target):
    n = len(nums)
    for i in range(n):
        for j in range(i+1, n): # 같은 원소가 있으면 안된다.
            # 각 원소의 합이 정답과 일치하면 True
            if nums[i] + nums[j] == target:
                return True
    # 아니면 False
    return False

print(twoSum(nums=[4,1,9,7,5,3,16], target=14))