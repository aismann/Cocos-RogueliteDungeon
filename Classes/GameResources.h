#ifndef __GAME_RESOURCES_H__
#define __GAME_RESOURCES_H__
#include <string>
/*-------------Loading------------------*/
const std::string LOADING_PLIST = "ui/loading.plist";
const std::string LOADING = "loading";
/*-------------Hero-----------------*/
const int HERO_TAG = 0;
const int KNIGHT_TAG = 1;
const int ELF_TAG = 2;
const int LIZARD_TAG = 3;
const int WIZARD_TAG = 4;
/*-------------Elf-----------------*/
const std::string ELF_M_PLIST = "hero/elf_m.plist";
const std::string ELF_M_BODY_PLIST = "hero/elf_m_body.plist";
const std::string ELF_M_HIT = "elf_m_hit";
const std::string ELF_M_IDLE = "elf_m_idle";
const std::string ELF_M_RUN = "elf_m_run";

/*-----------Knight----------------*/
const std::string KNIGHT_M_PLIST = "hero/knight_m.plist";
const std::string KNIGHT_M_BODY_PLIST = "hero/knight_m_body.plist";
const std::string KNIGHT_M_HIT = "knight_m_hit";
const std::string KNIGHT_M_IDLE = "knight_m_idle";
const std::string KNIGHT_M_RUN = "knight_m_run";

/*-----------Lizard----------------*/
const std::string LIZARD_M_PLIST = "hero/lizard_m.plist";
const std::string LIZARD_M_BODY_PLIST = "hero/lizard_m_body.plist";
const std::string LIZARD_M_HIT = "lizard_m_hit";
const std::string LIZARD_M_IDLE = "lizard_m_idle";
const std::string LIZARD_M_RUN = "lizard_m_run";

/*-----------Wizard----------------*/
const std::string WIZARD_F_PLIST = "hero/wizard_f.plist";
const std::string WIZARD_F_BODY_PLIST = "hero/wizard_f_body.plist";
const std::string WIZARD_F_HIT = "wizard_f_hit";
const std::string WIZARD_F_IDLE = "wizard_f_idle";
const std::string WIZARD_F_RUN = "wizard_f_run";

/*-------------Weapon---------------*/
const std::string WEAPON_PLIST = "base_weapon/base_weapon.plist";
const std::string WEAPON_BODY_PLIST = "base_weapon/base_weapon_body.plist";
const std::string SWORD = "weapon_knight_sword";
const std::string BOW = "weapon_bow";

const int PLAYER_ATTACK_TAG = 5;
const std::string SWORD_SLASH_PLIST = "base_weapon/swordslash.plist";
const std::string SWORD_SLASH_BODY = "base_weapon/swordslashbody.plist";
const std::string SWORD_SLASH = "swordslash";
const std::string BOW_SHOT_PLIST = "base_weapon/arrowshot.plist";
const std::string BOW_SHOT_BODY = "base_weapon/arrowshotbody.plist";
const std::string BOW_SHOT = "weapon_arrow";

/*-------------ENEMY---------------*/
/*-------------SKELETON---------------*/
const int ENEMY_TAG = 6;
const int ENEMY_ATTACK_TAG = 7;
const std::string SKELETON_PLIST = "mobs/Skeleton.plist";
const std::string SKELETON_BODY_PLIST = "mobs/SkeletonBody.plist";
const std::string SKELETON_IDLE = "skeleton_idle";
const std::string SKELETON_RUN = "skeleton_run";
const std::string SKELETON_ATTACK = "skeleton_idle";

const std::string SKELETON_SLASH_PLIST = "base_weapon/SkeletonSlash.plist";
const std::string SKELETON_SLASH_BODY = "base_weapon/SkeletonSlashBody.plist";
const std::string SKELETON_SLASH = "skeleton_slash";

/*----------------ORC----------------*/

const std::string ORC_PLIST = "mobs/OrcShaman.plist";
const std::string ORC_BODY_PLIST = "mobs/OrcShamanBody.plist";
const std::string ORC_IDLE = "orc_shaman_idle";
const std::string ORC_RUN = "orc_shaman_run";
const std::string ORC_ATTACK = "orc_shaman_idle";

const std::string ORC_MAGIC_PLIST = "base_weapon/OrcMagic.plist";
const std::string ORC_MAGIC_BODY = "base_weapon/OrcMagicBody.plist";
const std::string ORC_MAGIC = "orc_magic";

/*----------------ZOMBIEBOSS----------------*/
const std::string ZOMBIEBOSS_PLIST = "mobs/BossZombie.plist";
const std::string ZOMBIEBOSS_BODY_PLIST = "mobs/BossZombieBody.plist";
const std::string ZOMBIEBOSS_IDLE = "boss_zombie_idle";
const std::string ZOMBIEBOSS_RUN = "boss_zombie_run";
const std::string ZOMBIEBOSS_ATTACK = "boss_zombie_idle";

const std::string ZOMBIEBOSS_PUNCH_PLIST = "base_weapon/BossZombiePunch.plist";
const std::string ZOMBIEBOSS_PUNCH_BODY = "base_weapon/BossZombiePunchBody.plist";
const std::string ZOMBIEBOSS_PUNCH = "zombie_punch";

const std::string ZOMBIEBOSS_GROUND_PLIST = "base_weapon/BossZombieGround.plist";
const std::string ZOMBIEBOSS_GROUND_BODY = "base_weapon/BossZombieGroundBody.plist";
const std::string ZOMBIEBOSS_GROUND = "zombie_ground";
/*-------------WALL---------------*/
const int WALL_TAG = 8;
#endif // !__GAME_RESOURCES_H__

