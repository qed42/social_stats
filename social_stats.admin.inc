<?php

/**
 * @file
 * Administrative page callbacks for Service Links module.
 */

/**
 * Settings form to select the social media for content types.
 */
function social_stats_content_types_form() {
  $form = array();
  $node_types = node_type_get_types();
  foreach ($node_types as $types) {
    $form['social_stats'][$types->type] = array(
      '#type' => 'fieldset',
      '#title' => $types->name,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['social_stats'][$types->type][$types->type] = array(
      '#type' => 'checkboxes',
      '#options' => drupal_map_assoc(array(
        t('Facebook'),
        t('Twitter'),
        t('Google Plus'),
        t('LinkedIn')
      )),
      '#default_value' => variable_get($types->type) ? variable_get($types->type) : NULL,
    );
  }
  return system_settings_form($form);
}
