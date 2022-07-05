const operations = [
  "pa",
  "pb",
  "sa",
  "sb",
  "ss",
  "ra",
  "rb",
  "rr",
  "rra",
  "rrb",
  "rrr",
] as const;

type Operation = typeof operations[number];

// 역연산
const reverse: { readonly [K in Operation]: Operation } = {
  pa: "pb",
  pb: "pa",
  sa: "sa",
  sb: "sb",
  ss: "ss",
  ra: "rra",
  rb: "rrb",
  rr: "rrr",
  rra: "ra",
  rrb: "rb",
  rrr: "rr",
};

interface State {
  left: number[];
  right: number[];
  operations: Operation[];
}

// 현 상태에서 그 연산이 가능한지
const meaningful: { readonly [K in Operation]: (state: State) => boolean } = {
  pa: ({ right }) => !!(right.length >= 1 && right[0]),
  pb: ({ left }) => !!(left.length >= 1 && left[0]),
  sa: ({ left }) => !!(left.length >= 2 && left[0] && left[1]),
  sb: ({ right }) => !!(right.length >= 2 && right[0] && right[1]),
  ss: (state) => meaningful["sa"](state) && meaningful["sb"](state),
  ra: ({ left }) => !!(left.length >= 2 && left[0]),
  rb: ({ right }) => !!(right.length >= 2 && right[0]),
  rr: (state) => meaningful["ra"](state) && meaningful["rb"](state),
  rra: ({ left }) => !!(left.length >= 2 && left[left.length - 1]),
  rrb: ({ right }) => !!(right.length >= 2 && right[right.length - 1]),
  rrr: (state) => meaningful["rra"](state) && meaningful["rrb"](state),
};

// 현 상태에서 그 연산을 수행한 이후의 상태
const after: { [K in Operation]: (state: State) => State } = {
  pa: ({ left, right: [a, ...right], operations }) => ({
    left: [a, ...left],
    right,
    operations: [...operations, "pa"],
  }),
  pb: ({ left: [a, ...left], right, operations }) => ({
    left,
    right: [a, ...right],
    operations: [...operations, "pb"],
  }),
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
    left: [left[left.length - 1], ...left.slice(0, left.length - 1)],
    right,
    operations: [...operations, "rra"],
  }),
  rrb: ({ left, right, operations }) => ({
    left,
    right: [right[right.length - 1], ...right.slice(0, right.length - 1)],
    operations: [...operations, "rra"],
  }),
  rrr: ({ left, right, operations }) => ({
    left: [left[left.length - 1], ...left.slice(0, left.length - 1)],
    right: [right[right.length - 1], ...right.slice(0, right.length - 1)],
    operations: [...operations, "rrr"],
  }),
};

function stateKey({ left, right }: State): string {
  return `${left.join(", ")} / ${right.join(", ")}`;
}

function get_all_cases(
  initialState: State
): [number, Map<string, State>, State[][]] {
  const map: Map<string, State> = new Map();
  const list: State[][] = [];

  map.set(stateKey(initialState), initialState);
  list.push([initialState]);
  for (let distance = 0; ; distance++) {
    if (list[distance].length == 0) return [distance - 1, map, list];
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

function get_solution(
  left: number[],
  right: number[],
  filter: (state: State) => boolean
): [number, [number[], Operation[]][]] {
  const [, , list] = get_all_cases({
    left,
    right,
    operations: [],
  });
  const solution: [number[], Operation[]][] = list
    .flat(1)
    .filter(filter)
    .map((state) => [
      state.left,
      state.operations.reverse().map((op) => reverse[op]),
    ]);
  solution.sort((a, b) => {
    for (let i = 0; i < a[0].length; i++)
      if (a[0][i] != b[0][i]) return a[0][i] - b[0][i];
    return 0;
  });
  return [
    solution.reduce((acc, curr) => Math.max(acc, curr[1].length), 0),
    solution,
  ];
}

function c_style_print(
  name: string,
  count: number,
  alg: (count: number) => [number, [number[], Operation[]][]]
): void {
  const [distance, solution] = alg(count);
  console.log(
    "/* ************************************************************************** */"
  );
  console.log(
    "/*                                                                            */"
  );
  console.log(
    "/*                                                        :::      ::::::::   */"
  );
  console.log(
    `/*   ${(name + "_" + count + ".c").padEnd(
      50,
      " "
    )} :+:      :+:    :+:   */`
  );
  console.log(
    "/*                                                    +:+ +:+         +:+     */"
  );
  console.log(
    "/*   By: push_swap/bake.ts <powered-by@node.js>     +#+  +:+       +#+        */"
  );
  console.log(
    "/*                                                +#+#+#+#+#+   +#+           */"
  );
  console.log(
    "/*   Created: Automatically                            #+#    #+#             */"
  );
  console.log(
    "/*   Updated: Never                                   ###   ########.fr       */"
  );
  console.log(
    "/*                                                                            */"
  );
  console.log(
    "/* ************************************************************************** */"
  );
  console.log("\n#include <stddef.h>\n");
  console.log(
    `static const size_t\tg_${name}_${count}_distance = ${distance};`
  );
  console.log(`static const char\t*g_${name}_${count}[] = {`);
  solution.forEach((s) => {
    console.log(
      `\t"${s[1]
        .map((op) => `\\${(operations.indexOf(op) + 1).toString(8)}`)
        .join("")}",`
    );
  });
  console.log("};");
  console.log(
    `\nvoid\t${name}_${count}(\n\tconst char *const **out_ptr,\n\tsize_t *out_distance\n)\n{\n\t*out_ptr = g_${name}_${count};\n\t*out_distance = g_${name}_${count}_distance;\n}`
  );
}

const tst = (count: number) =>
  get_solution(
    [...Array.from(new Array(count)).map((_, i) => i + 1), 0],
    [0],
    (state) => state.left.length === count + 1 && state.left[count] === 0
  );
const tsb = (count: number) =>
  get_solution(
    [0, ...Array.from(new Array(count)).map((_, i) => i + 1)],
    [0],
    (state) => state.left.length === count + 1 && state.left[count] === 0
  );
const txt = (count: number) =>
  get_solution(
    [...Array.from(new Array(count)).map((_, i) => i + 1), 0],
    [],
    (state) => state.left.length === count + 1 && state.left[count] === 0
  );
const txb = (count: number) =>
  get_solution(
    [0, ...Array.from(new Array(count)).map((_, i) => i + 1)],
    [],
    (state) => state.left.length === count + 1 && state.left[count] === 0
  );
const tot = (count: number) =>
  get_solution(
    [0],
    [...Array.from(new Array(count)).map((_, i) => i + 1), 0],
    (state) => state.left.length === count + 1 && state.left[count] === 0
  );
const tos = (count: number) =>
  get_solution(
    [0],
    [...Array.from(new Array(count)).map((_, i) => i + 1)],
    (state) => state.left.length === count + 1 && state.left[count] === 0
  );
const tob = (count: number) =>
  get_solution(
    [0],
    [0, ...Array.from(new Array(count)).map((_, i) => i + 1)],
    (state) => state.left.length === count + 1 && state.left[count] === 0
  );
const sss = (count: number) =>
  get_solution(
    Array.from(new Array(count)).map((_, i) => i + 1),
    [0],
    (state) => state.left.length === count
  );
const sxs = (count: number) =>
  get_solution(
    Array.from(new Array(count)).map((_, i) => i + 1),
    [],
    (state) => state.left.length === count
  );
const sot = (count: number) =>
  get_solution(
    [],
    [...Array.from(new Array(count)).map((_, i) => i + 1), 0],
    (state) => state.left.length === count
  );
const sos = (count: number) =>
  get_solution(
    [],
    Array.from(new Array(count)).map((_, i) => i + 1),
    (state) => state.left.length === count
  );
const sob = (count: number) =>
  get_solution(
    [],
    [0, ...Array.from(new Array(count)).map((_, i) => i + 1)],
    (state) => state.left.length === count
  );
const bst = (count: number) =>
  get_solution(
    [...Array.from(new Array(count)).map((_, i) => i + 1), 0],
    [0],
    (state) => state.left.length === count + 1 && state.left[0] === 0
  );
const bsb = (count: number) =>
  get_solution(
    [0, ...Array.from(new Array(count)).map((_, i) => i + 1)],
    [0],
    (state) => state.left.length === count + 1 && state.left[0] === 0
  );
const bxt = (count: number) =>
  get_solution(
    [...Array.from(new Array(count)).map((_, i) => i + 1), 0],
    [],
    (state) => state.left.length === count + 1 && state.left[0] === 0
  );
const bxb = (count: number) =>
  get_solution(
    [0, ...Array.from(new Array(count)).map((_, i) => i + 1)],
    [],
    (state) => state.left.length === count + 1 && state.left[0] === 0
  );
const bot = (count: number) =>
  get_solution(
    [0],
    [...Array.from(new Array(count)).map((_, i) => i + 1), 0],
    (state) => state.left.length === count + 1 && state.left[0] === 0
  );
const bos = (count: number) =>
  get_solution(
    [0],
    [...Array.from(new Array(count)).map((_, i) => i + 1)],
    (state) => state.left.length === count + 1 && state.left[0] === 0
  );
const bob = (count: number) =>
  get_solution(
    [0],
    [0, ...Array.from(new Array(count)).map((_, i) => i + 1)],
    (state) => state.left.length === count + 1 && state.left[0] === 0
  );

declare const process: any;

(function main() {
  c_style_print(process.argv[2], parseInt(process.argv[3]), ({
    tst, tsb, txt, txb, tot, tos, tob,
    sss, sxs, sot, sos, sob,
    bst, bsb, bxt, bxb, bot, bos, bob,
  } as const)[process.argv[4] as 'sxs']);
})();
