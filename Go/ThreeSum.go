package main

import (
	"fmt"
	"time"
)

func CountInArray(a []int, n int) int {
	count := 0
	for _, v := range a {
		if v == n {
			count++
		}
	}
	return count
}

func Find(vv *[][]int, v *[]int) bool {
	if len(*vv) == 0 {
		return false
	}

	for _, a := range *vv {
		if len(a) != len(*v) {
			return false
		}

		found := true
		for _, n := range *v {
			if CountInArray(a, n) != CountInArray(*v, n) {
				found = false
				break
			}
		}

		if found {
			return true
		}
	}

	return false
}

func findThreeSum(nums []int, start int, sum int, a []int, result *[][]int) {
	if sum == 0 && len(a) == 3 {
		if !Find(result, &a) {
			temp := make([]int, len(a))
			copy(temp, a)
			*result = append(*result, temp)
		}
		return
	}

	if start == len(nums) || len(a) == 3 {
		return
	}

	for i := start; i < len(nums); i++ {
		a = append(a, nums[i])
		findThreeSum(nums, i+1, sum-nums[i], a, result)
		a = a[:len(a)-1]
	}
}

func threeSum(nums []int) [][]int {
	var result [][]int
	// for i := 0; i < len(nums)-2; i++ {
	// 	for j := i + 1; j < len(nums)-1; j++ {
	// 		for k := j + 1; k < len(nums); k++ {
	// 			if nums[i]+nums[j]+nums[k] == 0 {
	// 				v := []int{nums[i], nums[j], nums[k]}
	// 				if !Find(&result, &v) {
	// 					result = append(result, v)
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	var a []int
	findThreeSum(nums, 0, 0, a, &result)

	return result
}

func main() {
	v := []int{1, 1, 0, -1, -2, -3, 2, 3, -1}
	t := time.Now()
	for i := 0; i < 100000; i++ {
		threeSum(v)
	}

	d := time.Now().Sub(t)
	fmt.Println(d)

	r := threeSum(v)

	for i := 0; i < len(r); i++ {
		fmt.Printf("%d, %d, %d\n", r[i][0], r[i][1], r[i][2])
	}
}
