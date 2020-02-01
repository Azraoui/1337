<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'data' );

/** MySQL database username */
define( 'DB_USER', 'data' );

/** MySQL database password */
define( 'DB_PASSWORD', 'paspas' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '-33pYD}vt8LS^Am>$Zc<}?Cl:4FB*0:ox&^+ ji&&|{%LJ)+hi0fcH-Jz_e|+k:,');
define('SECURE_AUTH_KEY',  '3b]U0z>4[QVJ)|l|xnXG!=_W;GP,3@Ok};7Q)-*E!YxXR]2^oBkI(oW)lW=MR L8');
define('LOGGED_IN_KEY',    '|3UpK: R3{okf>] {r>)lX>pK2!/_VP[Z%W%9Ji{YL-*;:u)&tz~E;#m#<0S|OW(');
define('NONCE_KEY',        '@V2(IaFCCE|C!AMb<f&e~:KpM%s_3X+;A1 24Iswh5R&HHy ASM~1uFY&!VCvl7%');
define('AUTH_SALT',        'H>2H:6DE;7#bb<+$P*TIV=!7Cdj?]H?qv+@9q.lL]o3=84^u6Y*x{?:c-<p`Y}MJ');
define('SECURE_AUTH_SALT', 'J<l+QH1#%?2A+?=R/|!%+yh@Vds$y0x}G1#(8H+WC@KSx_+nyZ1C{cyOIo@&Aq)1');
define('LOGGED_IN_SALT',   '[[^vv-i2;-{-`n|*-6]I5C?+,us .Fn^sVjc8byBS_pCY?w%QJDHEW@MLKlmU^(6');
define('NONCE_SALT',       'dWz<}Oh:}stI_VKAqRnV%YAl9CzY3bF&EWZ25R,PgzPhvQ5J~gJuAV2mhT~|7!EL');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
