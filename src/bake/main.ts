const operations = [
  "ss", // sa와 sb를 동시에 수행함
  "sa", // left의 top 두 개를 교환함
  "sb", // right의 top 두 개를 교환함
  "pa", // left의 top을 right의 top으로 옮김
  "pb", // right의 top을 left의 top으로 옮김
  "rr", // ra와 rb를 동시에 수행함
  "ra", // left의 top을 left의 bottom으로 옮김
  "rb", // right의 top을 right의 bottom으로 옮김
  "rrr", // rra와 rrb를 동시에 수행함
  "rra", // left의 bottom을 left의 top으로 옮김
  "rrb", // right의 bottom을 right의 top으로 옮김
] as const;

type Operation = typeof operations[number];

// 역연산
const reverse: { readonly [K in Operation]: Operation } = {
  sa: "sa",
  sb: "sb",
  ss: "ss",
  pa: "pb",
  pb: "pa",
  ra: "rra",
  rb: "rrb",
  rr: "rrr",
  rra: "ra",
  rrb: "rb",
  rrr: "rr",
};

interface State {
  left: number[]; // 스택 A
  right: number[]; // 스택 B
  operations: Operation[]; // 현재까지 거친 연산 수
}

// 현 상태에서 그 연산이 의미 있는지
const meaningful: { readonly [K in Operation]: (state: State) => boolean } = {
  sa: ({ left }) => !!(left.length >= 2 && left[0] && left[1]),
  sb: ({ right }) => !!(right.length >= 2 && right[0] && right[1]),
  ss: (state) => meaningful["sa"](state) && meaningful["sb"](state),
  pa: ({ right }) => !!(right.length >= 1 && right[0]),
  pb: ({ left }) => !!(left.length >= 1 && left[0]),
  ra: ({ left }) => !!(left.length >= 2 && left[0]),
  rb: ({ right }) => !!(right.length >= 2 && right[0]),
  rr: (state) => meaningful["ra"](state) && meaningful["rb"](state),
  rra: ({ left }) => !(left.length >= 2 && left[left.length - 1]),
  rrb: ({ right }) => !(right.length >= 2 && right[right.length - 1]),
  rrr: (state) => meaningful["rra"](state) && meaningful["rrb"](state),
};

// 현 상태에서 그 연산을 수행한 이후의 상태
const after: { [K in Operation]: (state: State) => State } = {
  sa: ({ left: [a, b, ...left], right, operations }) => ({
    left: [b, a, ...left],
    right,
    operations: [...operations, "sa"],
  }),
  sb: ({ left, right: [a, b, ...right], operations }) => ({
    left,
    right: [b, a, ...right],
    operations: [...operations, "sb"],
  }),
  ss: ({ left: [a, b, ...left], right: [c, d, ...right], operations }) => ({
    left: [b, a, ...left],
    right: [d, c, ...right],
    operations: [...operations, "ss"],
  }),
  pa: ({ left: [a, ...left], right, operations }) => ({
    left,
    right: [a, ...right],
    operations: [...operations, "pa"],
  }),
  pb: ({ left, right: [a, ...right], operations }) => ({
    left: [a, ...left],
    right,
    operations: [...operations, "pb"],
  }),
  ra: ({ left: [a, ...left], right, operations }) => ({
    left: [...left, a],
    right,
    operations: [...operations, "ra"],
  }),
  rb: ({ left, right: [a, ...right], operations }) => ({
    left,
    right: [...right, a],
    operations: [...operations, "rb"],
  }),
  rr: ({ left: [a, ...left], right: [b, ...right], operations }) => ({
    left: [...left, a],
    right: [...right, b],
    operations: [...operations, "rr"],
  }),
  rra: ({ left, right, operations }) => ({
    left: [...left.slice(0, left.length - 1), left[left.length - 1]],
    right,
    operations: [...operations, "rra"],
  }),
  rrb: ({ left, right, operations }) => ({
    left,
    right: [...right.slice(0, right.length - 1), right[right.length - 1]],
    operations: [...operations, "rra"],
  }),
  rrr: ({ left, right, operations }) => ({
    left: [...left.slice(0, left.length - 1), left[left.length - 1]],
    right: [...right.slice(0, right.length - 1), right[right.length - 1]],
    operations: [...operations, "rrr"],
  }),
};

function stateKey({ left, right }: State): string {
  return `${left.join(", ")} / ${right.join(", ")}`;
}

function get_all_cases(initialState: State): [Map<string, State>, State[][]] {
  const map: Map<string, State> = new Map();
  const list: State[][] = [];

  map.set(stateKey(initialState), initialState);
  list.push([initialState]);
  for (let distance = 0; ; distance++) {
    if (list[distance].length == 0) return [map, list];
    list.push([]);
    list[distance].forEach((currentState) => {
      operations
        .filter((op) => meaningful[op](currentState))
        .forEach((op) => {
          const nextState = after[op](currentState);
          if (!map.has(stateKey(nextState))) {
            map.set(stateKey(nextState), nextState);
            list[distance + 1].push(nextState);
          }
        });
    });
  }
}

function get_solution(count: number): [number[], Operation[]][] {
  const [, list] = get_all_cases({
    left: Array.from(new Array(count)).map((_, i) => i + 1),
    right: [],
    operations: [],
  });
  const solution: [number[], Operation[]][] = list
    .flat(1)
    .filter((state) => state.left.length == count)
    .map((state) => [state.left, state.operations.map((op) => reverse[op])]);
  solution.sort((a, b) => {
    for (let i = 0; i < a.length; i++)
      if (a[0][i] != b[0][i]) return a[0][i] - b[0][i];
    return 0;
  });
  return solution;
}

function c_style_print(count: number): void {
  const solution = get_solution(count);
  console.log(`static const t_tuple_str_str\tg_solutions_${count}[] = {`);
  solution.forEach((s) => {
    console.log(
      `\t{"${s[0].map((n) => `\\${n.toString(8)}`)}", "${s[1]
        .map((op) => `\\${operations.indexOf(op).toString(8)}`)
        .join("")}"},`
    );
  });
  console.log('\t{"", ""}');
  console.log("};");
}

(function main() {
  c_style_print(9);
})();
