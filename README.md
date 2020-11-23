# UOSPC 2020
# 1. 문제 아이디어 작성(markdown)

## div2

| No.  | 문제명                                | 출제자 | 출제 난이도(solved.ac 기준) |
| ---- | ------------------------------------- | ------ | --------------------------- |
| 1    | 뽀문도로 기법(pomodoro)           | 최문기 | B3 ~ B1                     |
| 2    | *할로윈과 크리스마스의 중심에서(미정) | 최문기 | B1 ~ S3                     |
| 3    | 문기의 크리스마스 난제(x-mas)         | 최연웅 | S3                          |
| 4    | 연웅의 할로윈 난제(where_we_meet)     | 최문기 | S5 ~ S1                     |
| 5    | 코로나20(covid-20)                    | 최연웅 | G3                         |
| 6    | 물탱크 채우기(water-tanks)            | 김정현 |                             |
| 7    | 사진 찍어주세요!(big_picture)         | 최문기 | G4 ~ G2                     |
| 8    | 액자 놓기(frame)                      | 김정현 |                             |

## div1

| No.  | 문제명                                | 출제자 | 출제 난이도(solved.ac 기준) |
| ---- | ------------------------------------- | ------ | --------------------------- |
| 1    | *할로윈과 크리스마스의 중심에서(미정) | 최문기 | B1 ~ S3                     |
| 2    | 코로나20(covid-20)                    | 최연웅 |  G3                       |
| 3    | 물탱크 채우기(water-tanks)            | 김정현 |                             |
| 4    | 사진 찍어주세요!(big_picture)         | 최문기 | G4 ~ G2                     |
| 5    | 액자 놓기(frame)                      | 김정현 |                             |
| 6    | CUTTER!(cut_leaf)          | 최문기 | G2 ~ G1                     |
| 7    | 로봇 청소기(robotic-vacuum)           | 김정현 |                             |
| 8    | 정현이와 문기의 최선의 전략(best-strategy)     | 최연웅 | G2                  |

예비 문제

- 이산수학및컴퓨터알고리즘개론및실습및종합설계 (15학점) 기말 대체 과제(dmalg)
- Longest uncrossed bishop's path(longest_uncrossed_bishop)



# 2. 문제지 작성(markdown)

디스크립션 작성 및 포매팅 컨벤션 가이드

https://github.com/ucpcc/problemsetting-guidelines



# 3. Testcase 작성(polygon)

**polygon 튜토리얼** : http://www.secmem.org/blog/2019/05/17/polygon-how-to-use/

### 1. 소스코드 작성

- `Data_Generator.cpp`
- `Validator.cpp`(필수 아님, 데이터를 지문에 맞게 생성했는지 확인)
- `Checker.cpp`(스페셜 저지인 경우만 직접 작성)
- `solution_ac.cpp` `solution_wa.cpp` `solution_tle.cpp`

### 2. 파일 업로드

- Files: `Data_Generator.cpp` `Validator.cpp` `Checker.cpp` 업로드
- **Solution files**: `solution_ac.cpp` `solution_wa.cpp` `solution_tle.cpp` 업로드

### 3. 파일 연결

- **Checker**: 채점 방식을 관리 `Checker.cpp`
- **Validator**: 등록된 데이터가 valid한지 검사하는 프로그램을 관리 `Validator.cpp`
- **Tests**: 테스트 데이터를 관리 `Data_Generator.cpp`

### 4. 데이터 검증

- **Invocation**: 솔루션과 테스트 데이터를 선택하면 선택한 솔루션이 테스트 데이터에 대해 어떤 결과가 나오는지, 지정한 상태(Accepted, WA, TLE …)와 일치하는지를 검사

- Stresses: 정답 솔루션과 틀린 솔루션, 데이터 생성기를 등록하면 두 코드가 다른 답을 출력하는 데이터를 생성

### 5. 다운로드

- Packages: 위 메뉴들에서 관리한 모든 상태를 묶어 다운로드(-> test case 다운로드)



# 4. 풀이 작성

대회 끝나고 바로 공개 가능하도록!
