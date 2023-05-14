# Sort & Two Pointer
# Two Pointer 는 정렬이 된 상황에서 사용된다.
# 파이선에서의 Sort는 O(NlogN) 의 시간복잡도를 가지고 있다.

def twoSum(nums, target):
    nums.sort()
    l, r = 0, len(nums) - 1
    while l < r:
        if nums[l] + nums[r] == target:
            return True
        elif nums[l] + nums[r] > target:    # 두 합이 타겟보다 크면 뒷 포인터를 한칸 내림
            r -= 1
        elif nums[l] + nums[r] < target:    # 두 합이 타겟도바 작으면 앞 포인터를 한칸 올림
            l += 1
    return False


print(twoSum(nums=[4, 1, 9, 7, 5, 3, 16], target=14))

nums = [4, 4, 9, 7, 5, 3, 16]
pos = {idx : item for item, idx in enumerate(nums)}
print(pos)
