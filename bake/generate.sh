#!/bin/sh

set -e

cd "$(dirname "$0")"

npm run build

mkdir -p generated

seq 10 | while read line; do
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_tst "$line" tst > "generated/ps_hardcoded_tst_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_tsb "$line" tsb > "generated/ps_hardcoded_tsb_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_txt "$line" txt > "generated/ps_hardcoded_txt_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_txb "$line" txb > "generated/ps_hardcoded_txb_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_tot "$line" tot > "generated/ps_hardcoded_tot_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_tos "$line" tos > "generated/ps_hardcoded_tos_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_tob "$line" tob > "generated/ps_hardcoded_tob_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_sss "$line" sss > "generated/ps_hardcoded_sss_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_sxs "$line" sxs > "generated/ps_hardcoded_sxs_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_sot "$line" sot > "generated/ps_hardcoded_sot_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_sos "$line" sos > "generated/ps_hardcoded_sos_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_sob "$line" sob > "generated/ps_hardcoded_sob_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_bst "$line" bst > "generated/ps_hardcoded_bst_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_bsb "$line" bsb > "generated/ps_hardcoded_bsb_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_bxt "$line" bxt > "generated/ps_hardcoded_bxt_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_bxb "$line" bxb > "generated/ps_hardcoded_bxb_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_bot "$line" bot > "generated/ps_hardcoded_bot_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_bos "$line" bos > "generated/ps_hardcoded_bos_$line.c.txt"
  node --max_old_space_size=4096 dist/index.js ps_hardcoded_bob "$line" bob > "generated/ps_hardcoded_bob_$line.c.txt"
done
